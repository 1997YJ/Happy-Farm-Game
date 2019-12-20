#include "Seed.h"

Seed::Seed()
{
    productIndex = -1;
}
Seed::Seed(int seedClass):seedClass(seedClass)
{
    productIndex = index();
    breedTime.Start();
}


Seed::Seed(int seedClass, Time breedTime):seedClass(seedClass)
{
    productIndex = index();
    breedTime.Start();
}

Seed::Seed(int productIndex,Time breedTime,int matureTime): productIndex(productIndex),matureTime(matureTime)
{
    breedTime.Start();
}
int Seed::index()
{
    int num;
    if(seedClass==0)
    {
        srand((unsigned)time(nullptr));
        num = rand()%4;
    }
    else if(seedClass==1)
    {
        srand((unsigned)time(nullptr));
        num = rand()%8;
    }
    else {
        srand((unsigned)time(nullptr));
        num = rand()%12;
    }
    
    switch (num) {
        case 0:
            productIndex = 1;
            matureTime = 1;//10;
            
            return 1;
            break;
        case 1:
            productIndex = 3;
            matureTime = 3;//30;
            
            return 3;
            break;
        case 2:
            productIndex = 6;
            matureTime = 1;//90;
            return 6;
            break;
            
        case 3:
            productIndex = 10;
            matureTime = 1;//270;
            return 10;
            break;
        case 4:
            productIndex = 11;
            matureTime = 1;//360;
            return 11;
            break;
        case 5:
            productIndex = 19;
            matureTime = 1;//720;
            return 19;
            break;
        case 6:
            productIndex = 22;
            matureTime = 1;//1440;
            return 22;
            break;
        case 7:
            productIndex = 23;
            matureTime = 1;//2880;
            return 23;
            break;
        case 8:
            productIndex = 26;
            matureTime = 1;//2880;
            return 26;
            break;
        case 9:
            productIndex = 27;
            matureTime = 1;//3000;
            return 27;
            break;
        case 10:
            productIndex = 31;
            matureTime = 1;//3120;
            return 31;
            break;
        case 11:
            productIndex = 37;
            matureTime = 4;//3240
            return 37;
            break;
            
            
        default:
            return -1;
            break;
    }
}


bool Seed::mature()
{
    if(productIndex == -1)
        return false;
    
    cout<<breedTime.Pass()<<"pass"<<endl;
    breedTime.End();
    
    if(!(breedTime.Pass() < matureTime) && productIndex >-1)
        return true;
    else
        return false;
}

void Seed::harvest(Factory* afact)
{
    afact->productList[this->productIndex]->add(1);
    productIndex = -1;
}


void Seed::operator=(Seed s)
{
    this->breedTime = s.breedTime;
    this->matureTime = s.matureTime;
    this->productIndex =s.productIndex;
    this->seedClass = s.seedClass;
}

