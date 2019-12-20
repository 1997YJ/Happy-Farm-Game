/****************************************************************************
 <                 DSAP Final Project -  HappyFarm                    >
 FileName     [ Achievement.cpp ]
 Authors      [ Yen-Jung Hsu, Hao Cheng, Ugo Tan , Max Chen, Jonathan Chen ]
 Date         [ 2018/6/29 created ]
 ***************************************************************************/

#include "Achievement.h"



Achievement::Achievement()
{
    this->reach_or_not = false;
    this->count = 0;
    this->reachnum = 10;
    initLoadMUS();
    
}



void Achievement::add(Condition* a)
{
    //product(1-39) animal(40-43) order(44)
    if(this->reach_or_not == false)
    {
        this->count++;
        if(this->count >= this->reachnum){
            this->changeStatus();
            a->addExp(500);
            a->money += 100;
        }
    }
}


void Achievement::changeStatus()
{
    this->reach_or_not = true;
    muAchievement->PlayChunk(Music::cREACH);
    
}



bool Achievement::return_reach()
{
    return reach_or_not;
}

int Achievement::return_num()
{
    return count;
}

Music* AchievementArray::muAchievementArray = NULL;

AchievementArray::AchievementArray(SDL_Renderer* rR){
    
    frame=new Texture();
    number=new Texture();
    
    frame->LoadImagePNG("achievementbg", rR);
    
    frame->LoadImagePNG("house", rR);
    frame->LoadImagePNG("coin", rR);
    frame->LoadImagePNG("exp", rR);
    frame->LoadImagePNG("level", rR);
    
    frame->LoadImagePNG("wheat", rR);
    frame->LoadImagePNG("egg", rR);
    frame->LoadImagePNG("corn", rR);
    frame->LoadImagePNG("bread", rR);
    frame->LoadImagePNG("chickenFeed", rR);
    frame->LoadImagePNG("soybean", rR);
    frame->LoadImagePNG("cowFeed", rR);
    frame->LoadImagePNG("milk", rR);
    frame->LoadImagePNG("cream", rR);
    frame->LoadImagePNG("carrot", rR);
    frame->LoadImagePNG("sugarcane", rR);
    frame->LoadImagePNG("butter", rR);
    frame->LoadImagePNG("pigFeed", rR);
    frame->LoadImagePNG("pork", rR);
    frame->LoadImagePNG("bacon", rR);
    frame->LoadImagePNG("cookie", rR);
    frame->LoadImagePNG("baconEgg", rR);
    frame->LoadImagePNG("cheese", rR);
    frame->LoadImagePNG("sunflower", rR);
    frame->LoadImagePNG("carrotCake", rR);
    frame->LoadImagePNG("sunflowers", rR);
    frame->LoadImagePNG("chiliPepper", rR);
    frame->LoadImagePNG("tomato", rR);
    frame->LoadImagePNG("hamburger", rR);
    frame->LoadImagePNG("taco", rR);
    frame->LoadImagePNG("lettuce", rR);
    frame->LoadImagePNG("coffeebean", rR);
    frame->LoadImagePNG("espresso", rR);
    frame->LoadImagePNG("latte", rR);
    frame->LoadImagePNG("frappucino", rR);
    frame->LoadImagePNG("lemon", rR);
    frame->LoadImagePNG("zombieFeed", rR);
    frame->LoadImagePNG("cake", rR);
    frame->LoadImagePNG("coffeeCake", rR);
    frame->LoadImagePNG("zombiemeat", rR);
    frame->LoadImagePNG("sandwich", rR);
    frame->LoadImagePNG("chomper", rR);
    frame->LoadImagePNG("mixflowers", rR);
    frame->LoadImagePNG("chomperCake", rR);
    frame->LoadImagePNG("hen2", rR);
    frame->LoadImagePNG("cow2", rR);
    frame->LoadImagePNG("pig2", rR);
    frame->LoadImagePNG("zombie2", rR);
    frame->LoadImagePNG("orderlist2", rR);
    
    frame->LoadImagePNG("check", rR);
    
    number->LoadImagePNG("num_0", rR);
    number->LoadImagePNG("num_1", rR);
    number->LoadImagePNG("num_2", rR);
    number->LoadImagePNG("num_3", rR);
    number->LoadImagePNG("num_4", rR);
    number->LoadImagePNG("num_5", rR);
    number->LoadImagePNG("num_6", rR);
    number->LoadImagePNG("num_7", rR);
    number->LoadImagePNG("num_8", rR);
    number->LoadImagePNG("num_9", rR);
    
    
    
}




AchievementArray::~AchievementArray(){
}


void AchievementArray::drawAchievement(SDL_Renderer* rR)
{
    
    frame->Draw(rR, 0, 0,720,1280, 0);
    
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 11; j++) {
            frame->Draw(rR, 0, 0, 90, 90,85+100*j, 110+150*i, 4+11*i+j+1);
            int howmany = ACHIEVEMENTARRAY[11*i+j+1].return_num();
            number->Draw(rR, 0, 0, 40, 40,100+100*j, 205+150*i, howmany/10);
            number->Draw(rR, 0, 0, 40, 40,125+100*j, 205+150*i, howmany%10);
        }
    }
    

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 11; j++) {
            if(ACHIEVEMENTARRAY[i*11+j+1].return_reach()==true)
                frame->Draw(rR, 0, 0, 90, 90,110+100*j, 120+150*i, 49);
        }
    }
    
}


