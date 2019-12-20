

#ifndef Farm_h
#define Farm_h

#include "Texture.h"
#include "Seed.h"
#include "Factory.h"
#include "Music.h"





class Farm
{
private:
    Seed farmLand[32];
    bool farmField[32] = { 0 };
    bool harvesting =false;
    bool planting =false;
    int seedClass;
    Factory* afact;
    
    
    Texture* tFarm;
    //    static Music* muMenu;
    
    bool bigornot[6];
public:
    Farm();
    Farm(Factory* afact);
    ~Farm();
    const int farm_Height = 130;
    const int farm_Width = 130;
    const int farm_H = 3;
    const int farm_W = 6;
    
    static Music* muFarm;
    
    int seedAmount[3] ={0};
    void addSeed(int seedClass);
    void initFarm(SDL_Renderer* rR);
    void drawFarm(SDL_Renderer* rR);
    void breed(int i);
    void harvest(int i,AchievementArray* s,Condition* status);
    bool anyEmpty();
    
    int update(int mouseX, int mouseY, bool mouseLeftTrigger,AchievementArray* s,Condition* status);
    
};
#endif /* Farm_hpp */











