
#ifndef _GAMEMGR_H_
#define _GAMEMGR_H_

#include <iostream>
#include <SDL2/SDL.h>
#include "Achievement.h"
#include "Store.h"
#include "Order.h"
#include "Seed.h"
#include "Factory.h"
#include "FeedFactory.h"
#include "Product.h"
#include "Farm.h"
#include "Music.h"
#include "Condition.h"
#include "AnimalFarm.h"

static Music* muMenu;

enum gStats
{
    INIT,
    MENU,
    FARM,
    ANIMALFARM,
    ORDER,
    STORE,
    ACHIEVEMENT,
    FEEDFACTORY,
    FACTORY
};

class GameMgr
{
public:
    GameMgr();
    ~GameMgr();
    
    bool quitGame;
    
    //init
    void initLoadIMG();
    void initLoadMUS();
    
    // Loop
    void mainLoop();
    void Update();
    void Draw();
    
    //void resetMove();
    //static
    
    //static bool mouseLeftPressed, mouseRightPressed;
    //static int mouseX, mouseY;
    
    /* ----- get & set ----- */
    //static Map* getMap();
    //static Music* music;
    
    static int COMPUTER_SETTING;
    static int TIME_SETTING;
    
private:
    // ----- SDL -----
    SDL_Window * window;
    SDL_Renderer* rR;
    SDL_Event* mainEvent;
    Texture* gmTexture;
    
    // ------Data Structure pointer--------
    AchievementArray* aAchievementArray;
    Factory* aFactory;
    FeedFactory* aFeedFactory;
    Farm* aFarm;
    Store* aStore;
    Order *aOrder;
    Condition* aCondition;
    AnimalFarm *aAnimalFarm;
    
    // ----- FPS -----
    long frameTime;
    size_t frameCounter;
    static const int MIN_FRAME_TIME = 16;
    
    // ----- Keyboard & Mouse INPUT -----
    bool keyUp, keyDown, keyLeft, keyRight, keySpace, keySpaceTrigger;  // player1 control
    bool keyW, keyS, keyA, keyD, keyLShift, keyLShiftTrigger;           // player2 control
    unsigned inKey;
    unsigned KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_SPACE;
    unsigned KEY_w, KEY_s, KEY_a, KEY_d, KEY_LSHIFT;
    
    
    bool mouseLeftPressed, mouseRightPressed, mouseLeftTrigger, mouseRightTrigger;
    int mouseX, mouseY;
    
    void MouseInput();
    
    // ----- Game Data -----
    gStats NowStat;
};

#endif // _GAMEMGR_H_







