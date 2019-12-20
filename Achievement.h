/****************************************************************************
 <                 DSAP Final Project -  HappyFarm                    >
 FileName     [ Achievement.h ]
 Authors      [ Yen-Jung Hsu, Hao Cheng, Ugo Tan , Max Chen, Jonathan Chen ]
 Date         [ 2018/6/29 created ]
 ***************************************************************************/

#ifndef Achievement_h
#define Achievement_h

#include <SDL2/SDL.h>
#include "SDL2/SDL_image.h"
#include <string>
#include <iostream>
#include "Texture.h"
#include "Product.h"
#include "Condition.h"
#include "Music.h"

using namespace std;


/****Situation****
 get 10 of each products           ###39 (1-39)
 buy 10 of animals                 ###4  (40-43)
 finish 10 orders                  ###5  (44)
 *****************/

class Achievement
{
private:
    bool reach_or_not;
    int reachnum;
    int count;
    void changeStatus();
    Music* muAchievement;
    
    
public:
    Achievement();
    void initLoadMUS() { muAchievement = new Music; }
    void add(Condition* a);             //add count and check if reach
    bool return_reach();
    int return_num();
};


class AchievementArray
{
private:
    Texture* frame;
    Texture* number;
    
    
public:
    Achievement ACHIEVEMENTARRAY[45];

    static Music* muAchievementArray;
    
    AchievementArray(){};
    AchievementArray(SDL_Renderer* rR);
    ~AchievementArray();
    void drawAchievement(SDL_Renderer* rR);
    //void updateAchievement(int x, int y, bool mouseL);
    
};





#endif /* Achievement_h */


