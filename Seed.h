#ifndef Seed_h
#define Seed_h
#include "Product.h"
#include "Time.h"
#include "Factory.h"


/*
 ================
 INDEX NUMBERS
 ================
 1    wheat
 3    corn
 6    soybean
 10    carrot
 11    sugarcane
 19    sunflower
 22    chilipeper
 23    tomato
 26    lettuce
 27    coffeebean
 31    lemon
 37 chomper
 ================
 INDEX NUMBERS
 ================
 */


class Seed
{
private:
    Time breedTime;
    int matureTime;
    int index();
    
public:
    int seedClass;
    int productIndex;
    Seed();
    Seed(int seedClass);
    Seed(int seedClass,Time breedTime);
    Seed(int productIndex,Time breedTime,int matureTime);
    bool mature();
    void harvest(Factory* afact);
    void operator=(Seed s);
    
};

#endif /* Seed_h */



