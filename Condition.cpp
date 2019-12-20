#include "Condition.h"
Condition::Condition():frame(nullptr),money(0),experience(0),level(0),bigornot(false){
    initLoadMUS();
}
Condition::Condition(SDL_Renderer* rR):money(1000),experience(0),level(0),bigornot(false){
    frame=new Texture();
    initLoadMUS();
    frame->LoadImagePNG("house", rR);
    frame->LoadImagePNG("coin", rR);
    frame->LoadImagePNG("exp", rR);
    frame->LoadImagePNG("level", rR);
    
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
Condition::Condition(SDL_Renderer* rR,int money,int experience,int level):money(money),experience(experience),level(level),bigornot(false){
    
    frame=new Texture();
    number=new Texture();
    initLoadMUS();
    frame->LoadImagePNG("house", rR);
    frame->LoadImagePNG("coin", rR);
    frame->LoadImagePNG("exp", rR);
    frame->LoadImagePNG("level", rR);
    
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

void Condition::drawCondition(SDL_Renderer* rR){
    int big=0;
    if(bigornot)
        big+=20;
    
    frame->Draw(rR, 0,0,100+big,100+big,10-big/2, 0-big/2, 0);//home
    frame->Draw(rR, 0,0,60,60,150, 20, 1);//coin
    frame->Draw(rR, 0,0,60,60,450, 20, 2);//exp
    frame->Draw(rR, 0,0,80,80,690, 10, 3);//level
    
    string strmoney=to_string(this->money),strexp=to_string(this->experience),strlevel=to_string(this->level);
    
    int x=0;
    for(int i=0;i<strmoney.size();i++){
        int temp = strmoney[i]-'0';
        number->Draw(rR, 0,0,42,32,210+x,23,temp);
        x+=30;
    }
    
    int y=0;
    for(int i=0;i<strexp.size();i++){
        int temp = strexp[i]-'0';
        number->Draw(rR, 0,0,42,32,510+y,23,temp);
        y+=30;
    }
    
    int z=0;
    for(int i=0;i<strlevel.size();i++){
        int temp = strlevel[i]-'0';
        number->Draw(rR, 0,0,45,35,780+z,23,temp);
        z+=30;
    }
    
    
    
}

int Condition::updateCondtion(int x, int y, bool mouseL){
    
    
    if(x>10 && x<110 &&y>0 &&y<100)
        bigornot=true;
    else
        bigornot=false;
    
    if(x>10 && x<110 &&y>0 &&y<100 && mouseL){
        muCondition->PlayChunk(Music::cSTATUS);
        return 1;
        
    }
    else{
        return 0;
    }
}
void Condition::addExp(int exp){
    this->experience+=exp;
    if(this->experience >= this->level*1000){
        level++;
        muCondition->PlayChunk(Music::cLEVELUP);
        this->experience=0;
    }
    else{
        if(exp>0)
            muCondition->PlayChunk(Music::cEXP);
    }
    
    
    
}


