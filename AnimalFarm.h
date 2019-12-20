
#pragma once

#ifndef _ANIMALFARM_H_
#define _ANIMALFARM_H_


#include <SDL2/SDL.h>
//#include <SDL2/SDL_ttf.h>
#include "Texture.h"
#include "Music.h"
#include "Animal.h"
#include "Factory.h"
#include "LinkedList.h"
#include <string>


class AnimalFarm
{
private:
    int numAnimal[4]={0};
    Factory* aFact;
    AchievementArray* s;
    Condition* status;
public:
    LinkedList<Animal*> animalList;
    
    static Music* muAnimalFarm;
    AnimalFarm();
    AnimalFarm(Factory* aFact,AchievementArray* s,Condition* status);
    void loadImage(SDL_Renderer* rR);    // called at GameMgr.constructor
    
    // 先把這實作完
    bool add(string animalName);
    void remove(int index);
    void feed(int index);
    void produce();
    
    void detectDeadRemove();    // detect by gameLoop() contineously
    void updateAnimalFarm(int x, int y, bool mouseL);
    void drawAnimalFarm(SDL_Renderer* rR);
    
    Texture* tAnimalFarm;
};

#endif // _ANIMALFARM_H_









