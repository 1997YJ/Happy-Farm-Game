#ifndef FeedFactory_h
#define FeedFactory_h



#include <SDL2/SDL.h>
#include "SDL2/SDL_ttf.h"
#include "Texture.h"
#include "Product.h"
#include "Factory.h"
#include "Achievement.h"
#include "Condition.h"
#include "Wip.h"
#include "Music.h"

class making{
public:
    int a;
    int b;
    int c;
    making(){};
    making(int a,int b ,int c):a(a),b(b),c(c){};
    bool isSame(int* input){
        if(input[0]==a &&input[1]==b&&input[2]==c)
            return true;
        else if(input[0]==a &&input[1]==c &&input[2]==b)
            return true;
        else if(input[0]==b &&input[1]==a &&input[2]==c)
            return true;
        else if(input[0]==b &&input[1]==c &&input[2]==a)
            return true;
        else if(input[0]==c &&input[1]==a &&input[2]==b)
            return true;
        else if(input[0]==c &&input[1]==b &&input[2]==a)
            return true;
        else
            return false;
    }
    
};

class FeedFactory
{
public:
    
    FeedFactory(){};
    FeedFactory(SDL_Renderer *rR);
    ~FeedFactory();
    
    int updateFeedFactory(int x, int y, bool mouseL,Condition* status,Product** productList,AchievementArray* s);
    
    void drawFeedFactory(SDL_Renderer* rR,Product** productList);
    
    static Music* muFeedFactory;
    
    
private:
    Texture* tFeedFactory;
    
    making match[4];
    //
    //    const int feed_ch[3] = {1, 1, 3};
    //    const int feed_co[3] = {3, 6, 6};
    //    const int feed_pi[3] = {6, 10, 10};
    //    const int feed_zo[3] = {19, 19, 31};
    
    int materials[3];
    
    int waiting[2];
    
    //vector<int> workInProgress;
    
    int material_count = 0;
    int waiting_count=0;
    
    wip nowwaiting[2];
    
    
    int output;
    
    
};

#endif /* FeedFactory_h */

