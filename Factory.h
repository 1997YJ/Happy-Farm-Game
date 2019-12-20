#ifndef _FACTORY_H_
#define _FACTORY_H_


#include <SDL2/SDL.h>
#include "SDL2/SDL_ttf.h"
#include "Texture.h"
#include "Product.h"
#include "Wip.h"
#include "Time.h"
#include "Condition.h"
#include "Achievement.h"
#include "Music.h"
#include "LinkedQueue.h"
#include <string>

class Factory
{
public:
    Product** productList;
    
    Factory(){};
    Factory(SDL_Renderer *rR);
    ~Factory();
    
    int updateFactory(int x, int y, bool mouseL,AchievementArray* s ,Condition* status);
    void readImage(SDL_Renderer* rR);
    void drawFactory(SDL_Renderer* rR, bool f);
    
    Texture* tFactory;
    static Music* muFactory;
    
    bool bigornot[2];
    
private:
    const int MATERIALS_MAX = 7;
    const int INPROGRESS_MAX = 3;
    
    int materials[7] = {0, 0, 0, 0, 0, 0, 0};
    LinkedQueue<wip> workInProgress;
    int output;
    
    string vecA = "0000111";
    string vecB = "0000008";
    string vecC = "0000088";
    string vecD = "000001414";
    string vecE = "00112212";
    string vecF = "022221414";
    string vecG = "0000888";
    string vecH = "0011101112";
    string vecI = "0000191919";
    string vecJ = "441518232626";
    string vecK = "33322222626";
    string vecL = "00000027";
    string vecM = "00000827";
    string vecN = "000091127";
    string vecO = "0011111231";
    string vecP = "01111122731";
    string vecQ = "441823262635";
    string vecR = "00019193737";
    string vecS = "01111123137";
};

#endif // _FACTORY_H_

















