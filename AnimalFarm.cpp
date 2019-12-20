#include "AnimalFarm.h"

int maxNum = 5;

Music* AnimalFarm::muAnimalFarm = NULL;

AnimalFarm::AnimalFarm()
{
    //    numChicken = 0
    //    numCow = 0
    //    numPig = 0
    //    numZombie = 0
}

AnimalFarm::AnimalFarm(Factory* aFact,AchievementArray* s,Condition* status):aFact(aFact),s(s),status(status)
{
    //    numChicken = 0;
    //    numCow = 0;
    //    numPig = 0;
    //    numZombie = 0;
}

void AnimalFarm::loadImage(SDL_Renderer *rR)
{
    tAnimalFarm = new Texture;
    tAnimalFarm->LoadImagePNG("hen2", rR);
    tAnimalFarm->LoadImagePNG("cow2", rR);
    tAnimalFarm->LoadImagePNG("pig2", rR);
    tAnimalFarm->LoadImagePNG("zombie2", rR);
    tAnimalFarm->LoadImagePNG("animalfarmbg", rR);
}

bool AnimalFarm::add(string animalName)
{
    int animalIndex = -1;
    if (animalName == "chicken")
    {
        animalIndex = 0;
    }
    else if (animalName == "cow")
    {
        animalIndex = 1;
    }
    else if (animalName == "pig")
    {
        animalIndex = 2;
    }
    else if (animalName == "zombie")
    {
        animalIndex = 3;
    }
    
    if (numAnimal[animalIndex] < maxNum) // < 4 (5)
    {
        Animal* aAnimal = new Animal(animalIndex);
        animalList.push(aAnimal);
        numAnimal[animalIndex]++;
        return true;
    }
    else
    {
        cout << "There are already 5 chickens, can not add more!!!" << endl;
        return false;
    }
}

void AnimalFarm::detectDeadRemove()
{
    if (animalList.getLengh() > 0)
    {
        for (int i = 1; i < animalList.getLengh() + 1; i++)
            // 0 ~ numChicken-1 (not more than 5 times)
        {
            cout << "start detect : " << endl;
            if (animalList[i]->getIsDead())
            {
                cout << "has get IsDead" << endl;
                remove(i);
            }
            cout << "finish detect" << endl;
        }
    }
    
}

void AnimalFarm::remove(int index)
{
    numAnimal[animalList[index]->farmIndex]--;
    animalList.remove(index);
    muAnimalFarm->PlayChunk(Music::cNOTREACH);
    
}


void AnimalFarm::drawAnimalFarm(SDL_Renderer* rR)
{
    // draw background
    tAnimalFarm->Draw(rR, 0, 0, 720, 1280, 4);  // animalfarmbg
    
    // draw animals
    int chickenX = 0;
    int cowX = 0;
    int pigX = 0;
    int zombieX = 0;
    
    aFact->productList[5]->drawProduct(rR, 813, 630, 100, 100);
    aFact->productList[7]->drawProduct(rR, 913, 630, 100, 100);
    aFact->productList[13]->drawProduct(rR, 1013, 630, 100, 100);
    aFact->productList[32]->drawProduct(rR, 1113, 630, 100, 100);
    
    int f[4] = {5,7,13,32};
    for (int i = 0; i < 4; i++) {
//        if (!aFact->productList[f[i]]->isGot()){  // if not got
//            aFact->tFactory->Draw(rR, 0, 0, 90, 90, 813+110*(i), 630, 12);
//        }
        int num3 = aFact->productList[f[i]]->onHand();
        if (num3 >= 100){
            int num1 = num3 / 100;
            num3 -= num1*100;
            aFact->tFactory->Draw(rR, 0, 0, 32, 32, 838+110*(i), 680, num1);
        }
        if (num3 >= 10){
            int num2 = num3 / 10;
            num3 -= num2*10;
            aFact->tFactory->Draw(rR, 0, 0, 32, 32, 858+110*(i), 680, num2);
        }
        aFact->tFactory->Draw(rR, 0, 0, 32, 32, 888+110*(i), 680, num3);
    }
    
    for (int i = 1;i < animalList.getLengh()+1; i++)
    {
        switch (animalList[i]->farmIndex)
        {
            case 0:
                if(animalList[i]->isProducing)
                    tAnimalFarm->Draw(rR, 0, 0, 100, 100, 120 * chickenX + 50, 200, 0);
                else
                    tAnimalFarm->Draw(rR, 0, 0, 100, 100, 120 * chickenX + 50+rand()%4*4, 200, 0);
                chickenX++;
                break;
                
            case 1:
                if(animalList[i]->isProducing)
                    tAnimalFarm->Draw(rR, 0, 0, 100, 100, 120 * (cowX + 5) + 50, 200, 1);
                else
                    tAnimalFarm->Draw(rR, 0, 0, 100, 100, 120 * (cowX + 5) + 50, 200+rand()%4*4, 1);
                cowX++;
                break;
                
            case 2:
                if(animalList[i]->isProducing)
                    tAnimalFarm->Draw(rR, 0, 0, 100, 100, 120 * pigX + 50, 500, 2);
                else
                    tAnimalFarm->Draw(rR, 0, 0, 100, 100, 120 * pigX + 50, 500+rand()%4*4, 2);
                pigX++;
                break;
                
            case 3:
                if(animalList[i]->isProducing)
                    tAnimalFarm->Draw(rR, 0, 0, 100, 100, 120 * (zombieX + 5) + 50, 500, 3);
                else
                    tAnimalFarm->Draw(rR, 0, 0, 100, 100, 120 * (zombieX + 5) + 50+rand()%4*4, 500, 3);
                zombieX++;
                break;
            default:
                break;
        }
    }
}



void AnimalFarm::feed(int index)
{
    cout<< animalList[index]->feedIndex<<endl;
    if (aFact->productList[animalList[index]->feedIndex]->available())
    {
        if(animalList[index]->feed()){
            aFact->productList[animalList[index]->feedIndex]->remove(1);
            if(animalList[index]->feedIndex==5)
                muAnimalFarm->PlayChunk(Music::cCHICKEN);
            else if(animalList[index]->feedIndex==7)
                muAnimalFarm->PlayChunk(Music::cCOW);
            else if(animalList[index]->feedIndex==13)
                muAnimalFarm->PlayChunk(Music::cPIG);
            else if(animalList[index]->feedIndex==32)
                muAnimalFarm->PlayChunk(Music::cZOMBIE);
        }
        
    }
    else
        muAnimalFarm->PlayChunk(Music::cNOFEED);
    
}
void AnimalFarm::produce()
{
    for(int index = 1; index < animalList.getLengh()+1; index++)
        if(animalList[index]->produce())
        {
            aFact->productList[animalList[index]->animalIndex]->add(1);
            s->ACHIEVEMENTARRAY[animalList[index]->animalIndex].add(status);
            muAnimalFarm->PlayChunk(Music::cEXP);
        }
}

void AnimalFarm::updateAnimalFarm(int x, int y, bool mouseL)
{
    detectDeadRemove();
    produce();
    
    int chickenX = 0;
    int cowX = 0;
    int pigX = 0;
    int zombieX = 0;
    
    for (int i = 1;i < animalList.getLengh() + 1; i++)
    {
        switch (animalList[i]->farmIndex)
        {
            case 0:
                if ((120 * chickenX + 50 < x) && (120 * chickenX + 50 + 100 > x) && (200 < y) && (200 + 100 > y) && mouseL)
                {
                    feed(i);
                }
                chickenX++;
                break;
                
            case 1:
                if ((120 * (cowX + 5) + 50 < x) && (120 * (cowX + 5) + 50 + 100 > x) && (200 < y) && (200 + 100 > y) && mouseL)
                {
                    feed(i );
                }
                cowX++;
                break;
                
            case 2:
                if ((120 * pigX + 50 < x) && (120 * pigX + 50 + 100 > x) && (500 < y) && (500 + 100 > y) && mouseL)
                {
                    feed(i );
                }
                pigX++;
                break;
                
            case 3:
                if ((120 * (zombieX + 5) + 50 < x) && (120 * (zombieX + 5) + 50 + 100 > x) && (500 < y) && (500 + 100 > y) && mouseL)
                {
                    feed(i );
                }
                zombieX++;
                break;
            default:
                break;
        }
    }
    
    
}







