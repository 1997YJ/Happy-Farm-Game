#include "Farm.h"
#include "GameMgr.h"

const int seedSize = 100;
const int farm_x = 200;
const int farm_y = 150;

Music* Farm::muFarm = NULL;

Farm::Farm()
{
    tFarm = new Texture();
    for(int i=0;i<6;i++) bigornot[i]=false;
}

Farm::Farm(Factory* afact):afact(afact)
{
    tFarm = new Texture();
    for(int i=0;i<6;i++) bigornot[i]=false;
}


Farm::~Farm()
{
    delete tFarm;
}


void Farm::initFarm(SDL_Renderer* rR)
{
    tFarm->LoadImagePNG("harvest", rR);
    tFarm->LoadImagePNG("Dirt", rR);
    tFarm->LoadImagePNG("darkGrass", rR);
    tFarm->LoadImagePNG("fieldbg", rR);
    tFarm->LoadImagePNG("normalSeed", rR);
    tFarm->LoadImagePNG("superSeed", rR);
    tFarm->LoadImagePNG("ultraSeed", rR);
    tFarm->LoadImagePNG("factory", rR);
    tFarm->LoadImagePNG("order", rR);
    tFarm->LoadImagePNG("store", rR);
    tFarm->LoadImagePNG("achievement", rR);
    tFarm->LoadImagePNG("feed", rR);
    tFarm->LoadImagePNG("animalFarm", rR);
    
    seedAmount[0]=3;
    
    
    
    
}


void Farm::drawFarm(SDL_Renderer* rR)
{
    tFarm->Draw(rR, 0, 0, 720, 1280, 3);
    tFarm->Draw(rR, 0, 0,100,100, 25, 180, 4);
    tFarm->Draw(rR, 0, 0,100,100, 25, 300, 5);
    tFarm->Draw(rR, 0, 0,100,100, 25, 420, 6);
    //    num
    
    for(int i=0;i<3;i++)
    {
        int num3 = seedAmount[i];
        if (num3 >= 100){
            int num1 = num3 / 100;
            num3 -= num1*100;
            afact->tFactory->Draw(rR, 0, 0, 32, 32, 38+25, 180+120*i, num1);
        }
        if (num3 >= 10){
            int num2 = num3 / 10;
            num3 -= num2*10;
            afact->tFactory->Draw(rR, 0, 0, 32, 32, 58+25, 180+120*i, num2);
        }
        afact->tFactory->Draw(rR, 0, 0, 32, 32, 88+25, 180+120*i, num3);
    }
    
    
    int a=0,b=0,c=0,d=0,e=0,f=0;
    if(bigornot[0]) a+=20;
    if(bigornot[1]) b+=20;
    if(bigornot[2]) c+=20;
    if(bigornot[3]) d+=20;
    if(bigornot[4]) e+=20;
    if(bigornot[5]) f+=20;
    
    
    tFarm->Draw(rR, 0, 0, 150+a, 150+a, farm_x-a/2, 550-a/2, 7); //Factory
    tFarm->Draw(rR, 0, 0, 150+b, 150+b, farm_x + 210-b/2, 550-b/2, 11); //FeedFac
    tFarm->Draw(rR, 0, 0, 150+c, 150+c, farm_x + 420-c/2, 550-c/2, 9); // store
    tFarm->Draw(rR, 0, 0, 150+d, 150+d, farm_x + 630-d/2, 550-d/2, 12); //animalfarm
    tFarm->Draw(rR, 0, 0, 150+e, 150+e, 1100-e/2, 180-e/2 , 8); //Order
    tFarm->Draw(rR, 0, 0, 150+f, 150+f, 1100-f/2, 180 + farm_Width * 1 +30-f/2, 10);  //Achievement
    
    //    tFarm->Draw(rR, 0, 0,150,150, 1100, 530, 1); //Rock
    
    
    
    
    
    //    tFarm->Draw(rR, 0, 0,150,150,25,530,0);//harvest
    
    
    for (int i = 0;i<farm_H;i++)
    {
        for (int j = 0;j<farm_W;j++)
        {
            if (!farmField[i * farm_W + j] )
            {
                tFarm->Draw(rR, 0, 0, farm_Height, farm_Width, farm_x + farm_Height * j, farm_y + farm_Width * i, 1);
            }
            else if(farmField[i * farm_W + j] )
            {
                tFarm->Draw(rR, 0, 0, farm_Height, farm_Width, farm_x + farm_Height * j, farm_y + farm_Width * i, 2);
                if((farmLand[i * farm_W + j].productIndex>-1)&&
                   !farmLand[i * farm_W + j].mature())
                {
                    switch (farmLand[i * farm_W + j].seedClass) {
                        case 0:
                            tFarm->Draw(rR, 0, 0, 100, 100, farm_x + farm_Height * j+(farm_Height-seedSize)/2,farm_y + farm_Width * i+(farm_Width-seedSize)/2, 4);
                            
                            break;
                        case 1:
                            tFarm->Draw(rR, 0, 0, 100, 100, farm_x + farm_Height * j+(farm_Height-seedSize)/2,farm_y + farm_Width * i+(farm_Width-seedSize)/2, 5);
                            
                            break;
                        default:
                            tFarm->Draw(rR, 0, 0, 100, 100, farm_x + farm_Height * j+(farm_Height-seedSize)/2,farm_y + farm_Width * i+(farm_Width-seedSize)/2, 6);
                            break;
                    }
                    
                }
                else if((farmLand[i * farm_W + j].productIndex>-1)&&
                        farmLand[i * farm_W + j].mature())
                {
                    afact->productList[farmLand[i * farm_W + j].productIndex]->drawProduct(rR, farm_x + farm_Height * j + 15, farm_y + farm_Width * i + 15, 100, 100);
                }
                
            }
            
        }
    }
    
    
    
}

void Farm::addSeed(int seedClass)
{
    seedAmount[seedClass]++;
}

void Farm::breed(int i)
{
    if(planting)
    {
        //    隨機生成
        Seed temp(this->seedClass);
        seedAmount[this->seedClass]--;
        farmLand[i] = temp;
        cout<<farmLand[i].productIndex<<"made"<<endl;
        farmField[i] = true;
        if(seedAmount[this->seedClass]==0)
            planting =false;
    }
}

void Farm::harvest(int i,AchievementArray* s,Condition* status)
{
    
    if (farmLand[i].mature() )
    {
        int index=farmLand[i].productIndex;
        s->ACHIEVEMENTARRAY[index].add(status);
        farmLand[i].harvest(this->afact);
        muFarm->PlayChunk(Music::cHARVEST);
        
        farmField[i] = false;
        harvesting = false;
    }
}
bool Farm::anyEmpty()
{
    bool anyEmpty =false;
    for(int i=0;i<32;i++)
    {
        if(farmLand[i].productIndex<0)
            anyEmpty = true;
    }
    return anyEmpty;
}

int Farm::update(int mouseX, int mouseY, bool mouseLeftTrigger,AchievementArray* s,Condition* status)
{
    //    Factory Button
    if ((farm_x< mouseX) && (farm_x+180> mouseX )&& (550 < mouseY) && (720 > mouseY )&& mouseLeftTrigger )
    {
        muFarm->PlayChunk(Music::cSELECT);
        return 8;
    }
    if ((farm_x< mouseX) && (farm_x+180> mouseX )&& (550 < mouseY) && (720 > mouseY ))
        bigornot[0]=true;
    else
        bigornot[0]=false;
    
    //    FeedFac Button
    if ((farm_x+210 < mouseX) && (farm_x+360> mouseX )&& (550 < mouseY) && (720 > mouseY )&& mouseLeftTrigger )
    {
        muFarm->PlayChunk(Music::cSELECT);
        return 7;
    }
    if ((farm_x+210 < mouseX) && (farm_x+360> mouseX )&& (550 < mouseY) && (720 > mouseY ))
        bigornot[1]=true;
    else
        bigornot[1]=false;
    
    //    Store Button
    if ((farm_x+420 < mouseX) && (farm_x+570> mouseX )&& (550 < mouseY) && (720 > mouseY )&& mouseLeftTrigger )
    {
        muFarm->PlayChunk(Music::cSELECT);
        return 5;
    }
    if ((farm_x+420 < mouseX) && (farm_x+570> mouseX )&& (550 < mouseY) && (720 > mouseY ))
        bigornot[2]=true;
    else
        bigornot[2]=false;
    
    //    AnimalFarm Button
    if ((farm_x+630 < mouseX) && (farm_x+780> mouseX )&& (550 < mouseY) && (720 > mouseY )&& mouseLeftTrigger )
    {
        muFarm->PlayChunk(Music::cSELECT);
        return 3;
    }
    if ((farm_x+630 < mouseX) && (farm_x+780> mouseX )&& (550 < mouseY) && (720 > mouseY ))
        bigornot[3]=true;
    else
        bigornot[3]=false;
    
    //    Order Button
    if ((1100 < mouseX) && (1250 > mouseX )&& (180  < mouseY) && (farm_y +150 > mouseY )&& mouseLeftTrigger )
    {
        muFarm->PlayChunk(Music::cSELECT);
        return 4;
    }
    if ((1100 < mouseX) && (1250 > mouseX )&& (180  < mouseY) && (farm_y +150 > mouseY ))
        bigornot[4]=true;
    else
        bigornot[4]=false;
    
    //    Achievement Button
    if ((1100 < mouseX) && (1250 > mouseX )&& (180 + farm_Width * 1+30 < mouseY) && (farm_y + farm_Width * 1+30 +150 > mouseY )&& mouseLeftTrigger )
    {
        muFarm->PlayChunk(Music::cSELECT);
        return 6;
    }
    if ((1100 < mouseX) && (1250 > mouseX )&& (180 + farm_Width * 1+30 < mouseY) && (farm_y + farm_Width * 1+30 +150 > mouseY ))
        bigornot[5]=true;
    else
        bigornot[5]=false;
    
    //    SEED
    if ((25< mouseX )&& (125> mouseX) && ( 180 < mouseY) && (280 > mouseY )&& mouseLeftTrigger) {
        muFarm->PlayChunk(Music::cSEEDSET);
        if(seedAmount[0]>0)
        {
            planting = true;
            seedClass = 0;
        }
    }
    else if ((25< mouseX )&& (125> mouseX) && ( 300 < mouseY) && (400 > mouseY )&& mouseLeftTrigger) {
        muFarm->PlayChunk(Music::cSEEDSET);
        if(seedAmount[1]>0)
        {
            planting = true;
            seedClass = 1;
        }
    }
    else if ((25< mouseX )&& (125> mouseX) && ( 420 < mouseY) && (520 > mouseY )&& mouseLeftTrigger) {
        muFarm->PlayChunk(Music::cSEEDSET);
        if(seedAmount[2]>0)
        {
            planting = true;
            seedClass = 2;
        }
    }
    
    
    
    
    
    
    
    //    //    Harvest Button
    //    if ((25< mouseX) && (175> mouseX )&& (530 < mouseY) && (680 > mouseY )&& mouseLeftTrigger ) {
    //        harvesting = true;
    //        cout<<"harvest"<<endl;
    //    }
    
    //
    for (int i = 0;i<farm_H;i++)
    {
        for (int j = 0;j<farm_W;j++)
        {
            if (((farm_x + farm_Height * j) < mouseX) && ((farm_x + farm_Height * (j + 1)) > mouseX) && ((farm_y + farm_Width * i) < mouseY) && ((farm_y + farm_Width * (i + 1)) > mouseY))
            {
                if(planting)
                {
                    farmField[i * farm_W + j] = true;
                    
                }
                if (mouseLeftTrigger && farmLand[i * farm_W + j].productIndex > 0)
                {
                    harvest(i * farm_W + j,s,status);
                    
                }
                else if (mouseLeftTrigger && farmLand[i * farm_W + j].productIndex < 0)
                {
                    breed(i * farm_W + j);
                }
            }
            else if (farmLand[i * farm_W + j].productIndex < 0)
            {
                farmField[i * farm_W + j] = false;
            }
            
        }
    }
    
    
    
    
    return 2;
}











