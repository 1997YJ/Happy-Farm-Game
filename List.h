
#ifndef LIST_h
#define LIST_h

#include <stdio.h>
#include <stdio.h>
#include "Texture.h"
#include "Product.h"
#include "Factory.h"
#include "Util.h"
class Item{
    
public:
    int product;
    int amount;
    Item(){};
    
    Item(int max){
        
        product = rand() % (max )+1 ;
        amount = rand() % 9 +1;
        
    };
    void change(int max){
        product = rand() % (max )+1 ;
        amount = rand() % 9 +1;
    }
    
    ~Item(){};
    
};

class List{
private:
    Item *s[3];
    //    Item *two;
    //    Item *three;
    int max;
    int min;
public:
    //List():one(nullptr),two(nullptr),three(nullptr){};
    List(){};
    List(int max);
    
    void draw(SDL_Renderer *rR,Product** product,int x,Texture* number );
    
    bool updateList(int max,Product** product);
    
    void change(int max);
    
    ~List(){};
};


#endif /* list_hpp */


