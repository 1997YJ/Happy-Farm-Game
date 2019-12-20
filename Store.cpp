#include "Store.h"

Music* Store::muStore = NULL;

Store::Store(SDL_Renderer*rR){
    frame = new Texture();
    number = new Texture();
    
    for(int i=0;i<7;i++)bigornot[i]=false;
    
    frame->LoadImagePNG("storebg", rR);
    frame->LoadImagePNG("buy", rR);
    
}
void Store::drawStore(SDL_Renderer *rR){
    frame->Draw(rR, 0,0,720,1280, 0);
    
    int a=0,b=0,c=0,d=0,e=0,f=0,g=0;
    if(bigornot[0]) a+=20;
    if(bigornot[1]) b+=20;
    if(bigornot[2]) c+=20;
    if(bigornot[3]) d+=20;
    if(bigornot[4]) e+=20;
    if(bigornot[5]) f+=20;
    if(bigornot[6]) g+=20;
    
    frame->Draw(rR,0,0,70+a,70+a, 510-a/2, 250-a/2, 1);//buy
    
    
    frame->Draw(rR,0,0,70+b,70+b, 510-b/2, 390-b/2, 1);//buy
    
    
    frame->Draw(rR,0,0,70+c,70+c, 510-c/2, 530-c/2, 1);//buy
    
    
    
    frame->Draw(rR,0,0,70+d,70+d, 1120-d/2,230-d/2, 1);//buy
    
    
    frame->Draw(rR,0,0,70+e,70+e, 1120-e/2,340-e/2, 1);//buy
    
    
    frame->Draw(rR,0,0,70+f,70+f, 1120-f/2,450-f/2, 1);//buy
    
    frame->Draw(rR,0,0,70+g,70+g, 1120-g/2,560-g/2, 1);//buy
    
    //
    
    
    
}
void Store::updateStore(int x, int y, bool mouseL,AchievementArray* s,Condition* status,Farm* myfarm,AnimalFarm* myanimal
                        ){
    
    if(x>510 && x<580 && y>250 && y<320)
        bigornot[0]=true;
    else
        bigornot[0]=false;
    
    if(x>510 && x<580 && y>390 && y<460)
        bigornot[1]=true;
    else
        bigornot[1]=false;
    
    if(x>510 && x<580 && y>530 && y<600)
        bigornot[2]=true;
    else
        bigornot[2]=false;
    
    if(x>1120 && x<1190 && y>230 && y<300)
        bigornot[3]=true;
    else
        bigornot[3]=false;
    
    
    if(x>1120 && x<1190 && y>340 && y<410)
        bigornot[4]=true;
    else
        bigornot[4]=false;
    
    if(x>1120 && x<1190 && y>450 && y<520)
        bigornot[5]=true;
    else
        bigornot[5]=false;
    
    if(x>1120 && x<1190 && y>560 && y<630)
        bigornot[6]=true;
    else
        bigornot[6]=false;
    
    
    //int money=status->money;
    
    if(x>510 && x<580 && y>250 && y<320 &&mouseL){//normalseed
        cout<<"buy normal seed\n";
        
        if(status->money<1)
            cout<<"not enough to buy normal seed\n";
        else{
            muStore->PlayChunk(Music::cBUY);
            status->money-=1;
            myfarm->addSeed(0);
            
        }
        
        
    }
    if(x>510 && x<580 && y>390 && y<460 &&mouseL){//seed
        cout<<"buy super seed\n";
        if(status->money<20)
            cout<<"not enough to buy super seed\n";
        else{
            muStore->PlayChunk(Music::cBUY);
            status->money-=20;
            myfarm->addSeed(1);
        }
        
    }
    else if(x>510 && x<580 && y>530 && y<600 &&mouseL){//seed
        cout<<"buy ultra seed\n";
        if(status->money<50)
            cout<<"not enough to buy ultra seed\n";
        else{
            muStore->PlayChunk(Music::cBUY);
            status->money-=50;
            myfarm->addSeed(2);
        }
        
        
    }
    else if(x>1120 && x<1190 && y>230 && y<300 &&mouseL){//chicken
        cout<<"buy chicken\n";
        if(status->money<50||!myanimal->add("chicken")){
            cout<<"not enough to buy chicken \n";
            muStore->PlayChunk(Music::cWRONG);
        }
        else{
            muStore->PlayChunk(Music::cBUY);
            s->ACHIEVEMENTARRAY[40].add(status);
            //myanimal->add("chicken");
            status->money-=50;
        }
        
    }
    else if(x>1120 && x<1190 && y>340 && y<410 &&mouseL){//cow
        cout<<"buy cow\n";
        if(status->money<100||! myanimal->add("cow")){
            cout<<"not enough to bur cow\n";
            muStore->PlayChunk(Music::cWRONG);
        }
        else{
            muStore->PlayChunk(Music::cBUY);
            s->ACHIEVEMENTARRAY[41].add(status);
            //myanimal->add("cow");
            status->money-=100;
        }
        
    }
    else if(x>1120 && x<1190 && y>450 && y<520 &&mouseL){//pig
        cout<<"buy pig\n";
        if(status->money<100||!myanimal->add("pig")){
            cout<<"not enough to buy pig\n";
            muStore->PlayChunk(Music::cWRONG);
        }
        else{
            muStore->PlayChunk(Music::cBUY);
            s->ACHIEVEMENTARRAY[42].add(status);
            //myanimal->add("pig");
            status->money-=100;
        }
        
    }
    else if(x>1120 && x<1190 && y>560 && y<630 &&mouseL){//zombie
        cout<<"buy zombie\n";
        if(status->money<500||!myanimal->add("zombie")){
            
            cout<<"not enough to bur zombie\n";
            muStore->PlayChunk(Music::cWRONG);
        }
        else{
            muStore->PlayChunk(Music::cBUY);
            s->ACHIEVEMENTARRAY[43].add(status);
            //myanimal->add("zombie");
            status->money-=500;
        }
        
    }
    
    
    
}








