#include "Order.h"

Music* Order::muOrder = NULL;

Order::Order(SDL_Renderer* rR){
    for(int i=0;i<3;i++){
        k[i]=new List(10);
        bigornot[i]=false;
    }
    
    
    
    frame=new Texture();
    number=new Texture();
    
    frame->LoadImagePNG("orderbg", rR);
    frame->LoadImagePNG("orderList", rR);
    
    frame->LoadImagePNG("submit", rR);
    
    
    
    
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

void Order::drawOrder(SDL_Renderer *rR,Product** a){
    frame->Draw(rR, 0,0,720,1280, 0);
    
    
    frame->Draw(rR,0,0,600,400,30, 100, 1);
    frame->Draw(rR,0,0,600,400,430,100, 1);
    frame->Draw(rR,0,0,600,400,840, 100, 1);
    
    k[0]->draw(rR,a,0,number);
    k[1]->draw(rR,a,400,number);
    k[2]->draw(rR,a,800,number);
    
    int x=0,y=0,z=0;
    
    if(bigornot[0])
        x+=20;
    if(bigornot[1])
        y+=20;
    if(bigornot[2])
        z+=20;
    
    frame->Draw(rR, 0,0,100+x,80+x,180-x/2, 530-x/2, 2);
    frame->Draw(rR, 0,0,100+y,80+y,580-y/2, 530-y/2, 2);
    frame->Draw(rR, 0,0,100+z,80+z,1000-z/2, 530-z/2, 2);
    
    
}


void Order::updateOrder(int x, int y, bool mouseL,Condition* status,Product** a,AchievementArray* s){
    int max=0;
    if(status->level<=3 && status->level>=0)
        max = status->level*10;
    else
        max=39;
    
    
    if(x>180 && x<260 && y>530 && y<630){
        bigornot[0]=true;
    }
    else
        bigornot[0]=false;
    
    if(x>580 && x<660 && y>530 && y<630){
        bigornot[1]=true;
    }
    else
        bigornot[1]=false;
    
    
    if(x>1000 && x<1080 && y>530 && y<630){
        bigornot[2]=true;
    }
    else
        bigornot[2]=false;
    
    
    
    if(x>180 && x<260 && y>530 && y<630 && mouseL){
        cout<<"update orderlist_1\n";
        if(k[0]->updateList(max, a)){
            status->money+=status->level*100;
            s->ACHIEVEMENTARRAY[44].add(status);
            muOrder->PlayChunk(Music::cREACH);
        }
        else{
            muOrder->PlayChunk(Music::cNOTREACH);
        }
        
    }
    else if(x>580 && x<660 && y>530 && y<630 && mouseL){
        cout<<"update orderlist_2\n";
        if(k[1]->updateList(max, a)){
            status->money+=status->level*100;
            s->ACHIEVEMENTARRAY[44].add(status);
            muOrder->PlayChunk(Music::cREACH);
        }
        else{
            muOrder->PlayChunk(Music::cNOTREACH);
        }
        
    }
    else if(x>1000 && x<1080 && y>530 && y<630 && mouseL){
        cout<<"update orderlist_3\n";
        if(k[2]->updateList(max, a)){
            status->money+=status->level*100;
            s->ACHIEVEMENTARRAY[44].add(status);
            muOrder->PlayChunk(Music::cREACH);
        }
        else{
            muOrder->PlayChunk(Music::cNOTREACH);
        }
        
    }
    
    
    
}






