#ifndef Store_h
#define Store_h

#include <stdio.h>
#include "Texture.h"
#include "Factory.h"
#include "Farm.h"
#include "Condition.h"
#include "Music.h"
#include "AnimalFarm.h"
class Store{
private:
    bool bigornot[7];
    Texture* frame;
    Texture* number;
    
    
public:
    Store():frame(nullptr){};
    Store(SDL_Renderer* rR);
    
    void drawStore(SDL_Renderer* rR);
    void updateStore(int x, int y, bool mouseL,AchievementArray* s,Condition* status,Farm* myfarm,AnimalFarm* myanimal
                     );
    ~Store(){};
    
    static Music* muStore;
    
    
};


#endif /* Store_hpp */




