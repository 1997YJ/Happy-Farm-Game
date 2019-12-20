#pragma once


#ifndef _ANIMAL_H
#define _ANIMAL_H

#include <iostream>
#include "Time.h"
#include "Texture.h"
//#include "TextureList.h"

#include "SDL2/SDL.h"
using namespace std;



// Animal---------------------------------------------------------
class Animal
{
protected:
    int x, y;
    
    int age;
    int produceTime;
    Time produceCounter;
    
public:
    Animal(int animalIndex);
    bool isProducing;
    // static Texture* tAnimal;
    //    void randomWalk();
    int animalIndex;
    int farmIndex;
    int feedIndex;
    bool feed();         // detect feed is enough or not(outer argument), and detect isProducing or not , and start producing.
    bool produce();        // detect by gameLoop() contineously
    bool getIsDead();
    
};

#endif // _ANIMAL_H





