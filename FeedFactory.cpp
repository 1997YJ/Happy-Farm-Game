#include "FeedFactory.h"

Music* FeedFactory::muFeedFactory = NULL;

FeedFactory::FeedFactory(SDL_Renderer *rR)
{
    output=0;
    
    
    tFeedFactory = new Texture();
    tFeedFactory->LoadImagePNG("feedfactorybg", rR);
    tFeedFactory->LoadImagePNG("clickAbove", rR);
    tFeedFactory->LoadImagePNG("notGot", rR);
    for (int i = 0; i < 10; i++) {
        tFeedFactory->LoadImagePNG("num_" + to_string(i), rR);
    }
    
    match[0] = {1, 1, 3};
    match[1] = {3, 6, 6};
    match[2] = {6, 10, 10};
    match[3] = {19, 19, 31};
    
    waiting[0]=0;
    waiting[1]=0;
    
    
    
}

FeedFactory::~FeedFactory()
{
    
}


int FeedFactory::updateFeedFactory(int x, int y, bool mouseL,Condition* status,Product** productList,AchievementArray* s)
{
    
    //    cout<<"product1:"<<nowwaiting[0].index<<"\n";
    //    cout<<"product2:"<<nowwaiting[1].index<<"\n";
    
    if (nowwaiting[0].index!=0){
        cout<<"produce1\n";
        bool done = false;
        if (output == 0)
            done = nowwaiting[0].produce();
        if (done){
            cout<<"product1 done \n";
            output = nowwaiting[0].index;
            nowwaiting[0] = nowwaiting[1];
            nowwaiting[1].reset();
            waiting_count--;
            //            cout<<"product1:"<<nowwaiting[0].index<<"\n";
            //            cout<<"product2:"<<nowwaiting[1].index<<"\n";
        }
    }
    
    
    
    
    if (x <= 250 && x >= 80 && y <= 375 && y >= 175 && mouseL){
        if(material_count<3 && productList[1]->available()){
            materials[material_count] = 1;
            productList[1]->remove(1);
            material_count++;
            muFeedFactory->PlayChunk(Music::cSELECT);
        }
    }else if (x <= 445 && x >= 275 && y <= 375 && y >= 175 && mouseL){
        if(material_count<3 && productList[3]->available()){
            materials[material_count] = 3;
            productList[3]->remove(1);
            material_count++;
            muFeedFactory->PlayChunk(Music::cSELECT);
            
        }
    }else if (x <= 640 && x >= 470 && y <= 375 && y >= 175 && mouseL){
        if(material_count<3 && productList[6]->available()){
            materials[material_count] = 6;
            productList[6]->remove(1);
            material_count++;
            muFeedFactory->PlayChunk(Music::cSELECT);
            
        }
    }else if (x <= 830 && x >= 660 && y <= 375 && y >= 175 && mouseL){
        if(material_count<3 && productList[10]->available()){
            materials[material_count] = 10;
            productList[10]->remove(1);
            material_count++;
            muFeedFactory->PlayChunk(Music::cSELECT);
            
        }
    }else if (x <= 1007 && x >= 837 && y <= 375 && y >= 175 && mouseL){
        if(material_count<3 && productList[19]->available()){
            materials[material_count] = 19;
            productList[19]->remove(1);
            material_count++;
            muFeedFactory->PlayChunk(Music::cSELECT);
            
        }
    }else if (x <= 1195 && x >= 1025 && y <= 372 && y >= 256 && mouseL){
        if(material_count<3 && productList[31]->available()){
            materials[material_count] = 31;
            productList[31]->remove(1);
            material_count++;
            muFeedFactory->PlayChunk(Music::cSELECT);
            
        }
    }
    
    
    
    
    if (x <= 1200 && x >= 995 &&  y <= 720&& y >= 490  && mouseL){
        // click output
        if(output!=0){
            productList[output]->add(1);
            s->ACHIEVEMENTARRAY[output].add(status);
            output = 0;
            muFeedFactory->PlayChunk(Music::cGETPRODUCT);
        }
        
    }
    
    if (x <= 1101 && x >= 975 && y <= 152 && y >= 86 && mouseL && material_count==3) {
        // click make
        
        if(match[0].isSame(materials)&& waiting_count<2){
            nowwaiting[waiting_count].assign(5, 1);
            waiting_count++;
            muFeedFactory->PlayChunk(Music::cPRODUCTOUT);
        }
        else if(match[1].isSame(materials)&&waiting_count<2){
            nowwaiting[waiting_count].assign(7,1);
            waiting_count++;
            muFeedFactory->PlayChunk(Music::cPRODUCTOUT);
            
        }
        else if(match[2].isSame(materials)&&waiting_count<2){
            nowwaiting[waiting_count].assign(13,1);
            waiting_count++;
            muFeedFactory->PlayChunk(Music::cPRODUCTOUT);
        }
        else if(match[3].isSame(materials)&&waiting_count<2){
            nowwaiting[waiting_count].assign(32,1);
            waiting_count++;
            muFeedFactory->PlayChunk(Music::cPRODUCTOUT);
        }
        else{
            productList[materials[0]]->add(1);
            productList[materials[1]]->add(1);
            productList[materials[2]]->add(1);
            muFeedFactory->PlayChunk(Music::cWRONG);
            
        }
        
        
        for(int i = 0; i < 3; i++){
            materials[i] = 0;
        }
        
        material_count = 0;
    }
    return 0;
}



void FeedFactory::drawFeedFactory(SDL_Renderer* rR,Product** productList)
{
    tFeedFactory->Draw(rR, 0, 0, 720, 1280, 0, 0, 0);  // bg

    
    //materials
    for (int i = 0; i < material_count; i++) {
        int index = materials[i];
        productList[index]->drawProduct(rR, 40+(170*i), 505, 150, 150);
    }
    
    
    //waiting progress
    
    if(nowwaiting[0].index!=0){
        int temp=nowwaiting[0].index;
        productList[temp]->drawProduct(rR, 90+(170*4), 520, 150, 150);
    }
    
    if(nowwaiting[1].index!=0){
        int temp=nowwaiting[1].index;
        productList[temp]->drawProduct(rR, 80+(170*3), 520, 150, 150);
    }
    
    if (output != 0){
        productList[output]->drawProduct(rR, 1020, 500, 175, 175);
        tFeedFactory->Draw(rR, 0, 0, 40, 80, 1050, 665, 1);
    }
    
    // product num
    int feednum[6] = {1,3,6,10,19,31};
    for(int i = 0; i < 6; i++){
        if (!productList[feednum[i]]->isGot()){  // if not got
            tFeedFactory->Draw(rR, 0, 0, 90, 90, 100+200*i, 330, 2);
        }
        int num3 = productList[feednum[i]]->onHand();
        if (num3 >= 100){
            int num1 = num3 / 100;
            num3 -= num1*100;
            tFeedFactory->Draw(rR, 0, 0, 32, 32, 100+200*i, 350, num1+3);
        }
        if (num3 >= 10){
            int num2 = num3 / 10;
            num3 -= num2*10;
            tFeedFactory->Draw(rR, 0, 0, 32, 32, 130+200*i, 350, num2+3);
        }
        tFeedFactory->Draw(rR, 0, 0, 32, 32, 160+200*i, 350 , num3+3);
    }
    
    
    

    //    else{
    //        if(nowwaiting[1]!=nullptr){
    //            int temp=nowwaiting[1]->index;
    //            productList[temp]->drawProduct(rR, 15+(116*3), 113, 90, 90);
    //        }
    //    }
    
    
    // end of products drawing
}

