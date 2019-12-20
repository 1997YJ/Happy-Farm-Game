#ifndef ORDER_h
#define ORDER_h

#include <stdio.h>
#include "Texture.h"
#include "Product.h"
#include "Factory.h"
#include "List.h"
#include "Util.h"
#include "Condition.h"
#include "Achievement.h"
#include "Music.h"
//int LEVEL=0;




class Order{
private:
    Texture* frame;
    Texture* number;
    
    List *k[3];
    bool bigornot[3];
    
    
public:
    Order(){};
    Order(SDL_Renderer* rR);
    
    void drawOrder(SDL_Renderer* rR,Product** a);
    
    void updateOrder(int x, int y, bool mouseL,Condition* status,Product** a,AchievementArray* s);
    
    static Music* muOrder;
    
    
};

#endif /* Order_hpp */


