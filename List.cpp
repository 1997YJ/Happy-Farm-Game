#include "List.h"

List::List(int max){
    this->max=max;
    
    
    for(int i=0;i<3;i++)
        s[i]=new Item(max);
    
    // if(s[0]->product==s[1]->product && s[2]->product != )
    
    while(s[0]->product==s[1]->product || s[1]->product==s[2]->product || s[2]->product==s[0]->product){
        if(s[0]->product==s[1]->product)
            s[0]->change(max);
        else if(s[1]->product==s[2]->product)
            s[1]->change(max);
        else if(s[2]->product==s[0]->product)
            s[2]->change(max);
        
    }
    
}

void List::draw(SDL_Renderer *rR, Product **product, int x, Texture *number){
    int a=s[0]->product,b=s[1]->product,c=s[2]->product;
    product[a]->drawProduct(rR, 105+x, 300, 90, 90);
    product[b]->drawProduct(rR, 105+x, 375, 90, 90);
    product[c]->drawProduct(rR, 105+x, 455, 90, 90);
    
    int one=s[0]->amount,two=s[1]->amount,three=s[2]->amount;
    // cout<<"list:"<<one<<" "<<two<<" "<<three<<"\n";
    
    number->Draw(rR, 0, 0, 55,55, 270+x, 315, one);
    number->Draw(rR, 0, 0,55,55, 270+x, 390,  two);
    number->Draw(rR, 0, 0,55,55, 270+x, 465,  three);
}
bool List::updateList( int max,Product **product){
    
    int a=s[0]->product,b=s[1]->product,c=s[2]->product;
    int one=s[0]->amount,two=s[1]->amount,three=s[2]->amount;
    
    if(product[a]->onHand() >= one && product[b]->onHand()>=two &&product[c]->onHand()>=three){
        
        product[a]->remove(one);
        product[b]->remove(two);
        product[c]->remove(three);
        
        change(max);
        
        cout<<"update succeed\n";
        
        return true;
    }
    else
        return false;
    
}

void List::change(int max){
    for(int i=0;i<3;i++)
        this->s[i]->change(max);
    
    while(s[0]->product==s[1]->product || s[1]->product==s[2]->product || s[2]->product==s[0]->product){
        if(s[0]->product==s[1]->product)
            s[0]->change(max);
        else if(s[1]->product==s[2]->product)
            s[1]->change(max);
        else if(s[2]->product==s[0]->product)
            s[2]->change(max);
        
    }
    
    
}





