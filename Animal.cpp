#include "Animal.h"

// Texture* Animal::tAnimal = NULL;

using namespace std;

int DEAD_AGE = 3; // produce 3 times >> dead

int CHICKEN_PRODUCE_TIME = 5;    // (second)
int COW_PRODUCE_TIME = 10;
int PIG_PRODUCE_TIME = 15;
int ZOMBIE_PRODUCE_TIME = 20;

int ANIMAL_FEED_INDEX = -1;
int CHICKEN_FEED_INDEX = 5;
int COW_FEED_INDEX = 7;
int PIG_FEED_INDEX = 13;
int ZOMBIE_FEED_INDEX = 32;

int ANIMAL_PRODUCT_INDEX = -1;
int CHICKEN_PRODUCT_INDEX = 2;    // egg
int COW_PRODUCT_INDEX = 8;        // milk
int PIG_PRODUCT_INDEX = 14;        //pork
int ZOMBIE_PRODUCT_INDEX = 35;    //zombiemeat

// Animal---------------------------------------------------------
Animal::Animal(int animalIndex)
{
    this->x = 0;
    this->y = 0;
    this->isProducing = false;
    this->age = 0;
    this->farmIndex = animalIndex;
    
    switch (animalIndex) {
        case 0:
            this->x = 10;
            this->y = 110;
            this->produceTime = CHICKEN_PRODUCE_TIME;
            this->feedIndex = CHICKEN_FEED_INDEX;
            this->animalIndex = CHICKEN_PRODUCT_INDEX;
            break;
            
        case 1:
            this->x = 20;
            this->y = 220;
            this->produceTime = COW_PRODUCE_TIME;
            this->feedIndex = COW_FEED_INDEX;
            this->animalIndex = COW_PRODUCT_INDEX;
            break;
            
        case 2:
            this->x = 30;
            this->y = 330;
            this->produceTime = PIG_PRODUCE_TIME;
            this->feedIndex = PIG_FEED_INDEX;
            this->animalIndex = PIG_PRODUCT_INDEX;
            break;
            
        case 3:
            this->x = 40;
            this->y = 440;
            this->produceTime = ZOMBIE_PRODUCE_TIME;
            this->feedIndex = ZOMBIE_FEED_INDEX;
            this->animalIndex = ZOMBIE_PRODUCT_INDEX;
            break;
        default:
            break;
    }
}


//
// detect feed is enough or not(detect in outer argument first, if true, then use this function),
// detect isProducing or not
//  >> start producing.
bool Animal::feed()
{
    if (!isProducing && age >= 0) // && feed is enough)
    {
        isProducing = true;
        produceCounter.Start();
        return true;
    }
    else
    {
        cout << "This animal has already been producing or dead!!!" << endl;
        return false;
    }
}

// when after time, end producing
// detect by gameLoop() contineously
bool Animal::produce()
{
    produceCounter.End();
    
    if (isProducing && produceCounter.Pass() > this->produceTime)
    {
        age++;
        isProducing = false;
        return true;
    }
    else
        return false;
}

bool Animal::getIsDead()
{
    return this->age == DEAD_AGE;
}





