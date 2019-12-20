#ifndef _PRODUCT_H_
#define _PRODUCT_H_


#include "Texture.h"

class Product
{
public:
    Product(int index, int price, SDL_Renderer* rR);
    ~Product();
    
    void readImage(SDL_Renderer* rR);
    void drawProduct(SDL_Renderer* rR, int x, int y, int h, int w);
    
    bool isGot() { return got; }
    bool available() { return (got and volume > 0);}
    int onHand() { return volume;}
    int getPrice() { return price; }
    
    void add(int howMuch);
    void remove(int howMuch);
    void sell(int howMuch);
    
private:
    int indexNum;  // index down below
    int price;
    int volume;
    bool got;
    
    Texture* tProduct;
};
/*
 ================
 INDEX NUMBERS
 ================
 1    wheat
 2    egg
 3    corn
 4    bread
 5    chickenFeed
 6    soybean
 7    cowFeed
 8    milk
 9    cream
 10    carrot
 11    sugarcane
 12    butter
 13    pigFeed
 14    pork
 15    bacon
 16    cookie
 17    baconEgg
 18    cheese
 19    sunflower
 20    carrotCake
 21    sunflowers
 22    chilipeper
 23    tomato
 24    hamburger
 25    taco
 26    lettuce
 27    coffeebean
 28    expresso
 29    latte
 30    frappucino
 31    lemon
 32    zombieFeed
 33    cake
 34    coffeeCake
 35    zombiemeat
 36    sandwich
 37    chomper
 38    mixflowers
 39    chomperCake
 ================
 INDEX NUMBERS
 ================
 */

#endif // _PRODUCT_H_


