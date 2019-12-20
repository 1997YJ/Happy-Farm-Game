#ifndef Condition_h
#define Condition_h

#include <stdio.h>
#include <string.h>
#include "Texture.h"
#include "Music.h"

class Condition{
private:
    Texture* frame;
    Texture* number;
    
    bool bigornot;
    Music* muCondition;
    
public:
    int money;
    int experience;
    int level;
    
    Condition();
    Condition(SDL_Renderer* rR);
    Condition(SDL_Renderer* rR,int money,int experience,int level);
    void initLoadMUS() { muCondition = new Music; }
    void drawCondition(SDL_Renderer* rR);
    
    int updateCondtion(int x, int y, bool mouseL);
    
    void addExp(int exp);
    
    
    
    
    
};



#endif /* Condition_hpp */


