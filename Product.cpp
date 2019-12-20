#include "Product.h"

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

Product::Product(int index, int p, SDL_Renderer* rR)
{
    indexNum = index;
    price = p;
    volume = 0;
    got = false;
    readImage(rR);
}


Product::~Product()
{
    delete tProduct;
}

void Product::readImage(SDL_Renderer* rR)
{
    tProduct = new Texture;
    if (indexNum == 1) {
        tProduct->LoadImagePNG("wheat", rR);
    } else if (indexNum == 2) {
        tProduct->LoadImagePNG("egg", rR);
    } else if (indexNum == 3 ) {
        tProduct->LoadImagePNG("corn", rR);
    } else if (indexNum == 4) {
        tProduct->LoadImagePNG("bread", rR);
    } else if (indexNum == 5) {
        tProduct->LoadImagePNG("chickenFeed", rR);
    } else if (indexNum == 6) {
        tProduct->LoadImagePNG("soybean", rR);
    } else if (indexNum == 7) {
        tProduct->LoadImagePNG("cowFeed", rR);
    } else if (indexNum == 8) {
        tProduct->LoadImagePNG("milk", rR);
    } else if (indexNum == 9) {
        tProduct->LoadImagePNG("cream", rR);
    } else if (indexNum == 10) {
        tProduct->LoadImagePNG("carrot", rR);
    } else if (indexNum == 11) {
        tProduct->LoadImagePNG("sugarcane", rR);
    } else if (indexNum == 12) {
        tProduct->LoadImagePNG("butter", rR);
    } else if (indexNum == 13) {
        tProduct->LoadImagePNG("pigFeed", rR);
    } else if (indexNum == 14) {
        tProduct->LoadImagePNG("pork", rR);
    } else if (indexNum == 15) {
        tProduct->LoadImagePNG("bacon", rR);
    } else if (indexNum == 16) {
        tProduct->LoadImagePNG("cookie", rR);
    } else if (indexNum == 17) {
        tProduct->LoadImagePNG("baconEgg", rR);
    } else if (indexNum == 18) {
        tProduct->LoadImagePNG("cheese", rR);
    } else if (indexNum == 19) {
        tProduct->LoadImagePNG("sunflower", rR);
    } else if (indexNum == 20) {
        tProduct->LoadImagePNG("carrotCake", rR);
    } else if (indexNum == 21) {
        tProduct->LoadImagePNG("sunflowers", rR);
    } else if (indexNum == 22) {
        tProduct->LoadImagePNG("chiliPepper", rR);
    } else if (indexNum == 23) {
        tProduct->LoadImagePNG("tomato", rR);
    } else if (indexNum == 24) {
        tProduct->LoadImagePNG("hamburger", rR);
    } else if (indexNum == 25) {
        tProduct->LoadImagePNG("taco", rR);
    } else if (indexNum == 26) {
        tProduct->LoadImagePNG("lettuce", rR);
    } else if (indexNum == 27) {
        tProduct->LoadImagePNG("coffeebean", rR);
    } else if (indexNum == 28) {
        tProduct->LoadImagePNG("espresso", rR);
    } else if (indexNum == 29) {
        tProduct->LoadImagePNG("latte", rR);
    } else if (indexNum == 30) {
        tProduct->LoadImagePNG("frappucino", rR);
    } else if (indexNum == 31) {
        tProduct->LoadImagePNG("lemon", rR);
    } else if (indexNum == 32) {
        tProduct->LoadImagePNG("zombieFeed", rR);
    } else if (indexNum == 33) {
        tProduct->LoadImagePNG("cake", rR);
    } else if (indexNum == 34) {
        tProduct->LoadImagePNG("coffeeCake", rR);
    } else if (indexNum == 35) {
        tProduct->LoadImagePNG("zombiemeat", rR);
    } else if (indexNum == 36) {
        tProduct->LoadImagePNG("sandwich", rR);
    } else if (indexNum == 37) {
        tProduct->LoadImagePNG("chomper", rR);
    } else if (indexNum == 38) {
        tProduct->LoadImagePNG("mixflowers", rR);
    } else if (indexNum == 39) {
        tProduct->LoadImagePNG("chomperCake", rR);
    }
}

void Product::drawProduct(SDL_Renderer* rR, int x, int y, int h, int w)
{
    tProduct->Draw(rR, 0, 0, h, w, x, y, 0);
}

void Product::add(int howMuch)
{
    if (!got){
        got = true;
    }
    volume += howMuch;
}
void Product::remove(int howMuch)
{
    if (volume >= howMuch){
        volume -= howMuch;
    }
}
void Product::sell(int howMuch)
{
    if (isGot() and volume >= howMuch){
        volume -= howMuch;
        // money -= howMuch * price;
    }
}


