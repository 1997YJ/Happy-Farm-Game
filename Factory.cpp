#include "Factory.h"

Music* Factory::muFactory = NULL;

Factory::Factory(SDL_Renderer *rR)
{
    output = 0;
    productList = new Product* [40];
    bigornot[0]=false;
    bigornot[1]=false;
    
    
    // 產品編號、價錢（productList[0]沒有東西）
    productList[1] = new Product(1, 3, rR);
    productList[2] = new Product(2, 18, rR);
    productList[3] = new Product(3, 7, rR);
    productList[4] = new Product(4, 21, rR);
    productList[5] = new Product(5, 15, rR);
    productList[6] = new Product(6, 10, rR);
    productList[7] = new Product(7, 32, rR);
    productList[8] = new Product(8, 32, rR);
    productList[9] = new Product(9, 50, rR);
    productList[10] = new Product(10, 7, rR);
    productList[11] = new Product(11, 14, rR);
    productList[12] = new Product(12, 82, rR);
    productList[13] = new Product(13, 32, rR);
    productList[14] = new Product(14, 50, rR);
    productList[15] = new Product(15, 65, rR);
    productList[16] = new Product(16, 200, rR);
    productList[17] = new Product(17, 201, rR);
    productList[18] = new Product(18, 122, rR);
    productList[19] = new Product(19, 25, rR);
    productList[20] = new Product(20, 130, rR);
    productList[21] = new Product(21, 100, rR);
    productList[22] = new Product(22, 36, rR);
    productList[23] = new Product(23, 43, rR);
    productList[24] = new Product(24, 400, rR);
    productList[25] = new Product(25, 225, rR);
    productList[26] = new Product(26, 50, rR);
    productList[27] = new Product(27, 64, rR);
    productList[28] = new Product(28, 100, rR);
    productList[29] = new Product(29, 120, rR);
    productList[30] = new Product(30, 165, rR);
    productList[31] = new Product(31, 93, rR);
    productList[32] = new Product(32, 150, rR);
    productList[33] = new Product(33, 220, rR);
    productList[34] = new Product(34, 290, rR);
    productList[35] = new Product(35, 100, rR);
    productList[36] = new Product(36, 430, rR);
    productList[37] = new Product(37, 100, rR);
    productList[38] = new Product(38, 330, rR);
    productList[39] = new Product(39, 330, rR);
    readImage(rR);
}
Factory::~Factory()
{
    for (int i = 1; i < 40; ++i) {
        delete[] productList[i];
    }
    productList = nullptr;
}

int Factory::updateFactory(int x, int y, bool mouseL,AchievementArray* s ,Condition* status)
{
    int exp = 0;
    if(output!=0&& x <= 1280 && x >= 1162 && y <= 226 && y >= 100)
        bigornot[0]=true;
    else
        bigornot[0]=false;
    
    if (!workInProgress.isEmpty()){
        bool done = false;
        if (output == 0)
            done = workInProgress[1].produce();
        if (done){
            int index = workInProgress[1].index;
            workInProgress.dequeue();
            output = index;
        }
    }
    // =================
    // click on products
    // =================
    if (x <= 128 && x >= 0 && y <= 372 && y >= 256 && mouseL){
        if (productList[1]->available()){
            for (int i = 0; i < 7; i++) {
                if (materials[i] == 0){
                    materials[i] = 1;
                    productList[1]->remove(1);
                    muFactory->PlayChunk(Music::cSELECT);
                    break;
                }
            }
        }
    }else if (x <= 256 && x >= 128 && y <= 372 && y >= 256 && mouseL){
        if (productList[2]->available()){
            for (int i = 0; i < 7; i++) {
                if (materials[i] == 0){
                    materials[i] = 2;
                    productList[2]->remove(1);
                    muFactory->PlayChunk(Music::cSELECT);
                    break;
                }
            }
        }
    }else if (x <= 384 && x >= 256 && y <= 372 && y >= 256 && mouseL){
        if (productList[3]->available()){
            for (int i = 0; i < 7; i++) {
                if (materials[i] == 0){
                    materials[i] = 3;
                    productList[3]->remove(1);
                    muFactory->PlayChunk(Music::cSELECT);
                    break;
                }
            }
        }
    }else if (x <= 512 && x >= 384 && y <= 372 && y >= 256 && mouseL){
        if (productList[4]->available()){
            for (int i = 0; i < 7; i++) {
                if (materials[i] == 0){
                    materials[i] = 4;
                    productList[4]->remove(1);
                    muFactory->PlayChunk(Music::cSELECT);
                    break;
                }
            }
        }
    }else if (x <= 640 && x >= 512 && y <= 372 && y >= 256 && mouseL){
        if (productList[5]->available()){
            for (int i = 0; i < 7; i++) {
                if (materials[i] == 0){
                    materials[i] = 5;
                    productList[5]->remove(1);
                    muFactory->PlayChunk(Music::cSELECT);
                    break;
                }
            }
        }
    }else if (x <= 768 && x >= 640 && y <= 372 && y >= 256 && mouseL){
        if (productList[6]->available()){
            for (int i = 0; i < 7; i++) {
                if (materials[i] == 0){
                    materials[i] = 6;
                    productList[6]->remove(1);
                    muFactory->PlayChunk(Music::cSELECT);
                    break;
                }
            }
        }
    }else if (x <= 896 && x >= 768 && y <= 372 && y >= 256 && mouseL){
        if (productList[7]->available()){
            for (int i = 0; i < 7; i++) {
                if (materials[i] == 0){
                    materials[i] = 7;
                    productList[7]->remove(1);
                    muFactory->PlayChunk(Music::cSELECT);
                    break;
                }
            }
        }
    }else if (x <= 1024 && x >= 896 && y <= 372 && y >= 256 && mouseL){
        if (productList[8]->available()){
            for (int i = 0; i < 7; i++) {
                if (materials[i] == 0){
                    materials[i] = 8;
                    productList[8]->remove(1);
                    muFactory->PlayChunk(Music::cSELECT);
                    break;
                }
            }
        }
    }else if (x <= 1152 && x >= 1024 && y <= 372 && y >= 256 && mouseL){
        if (productList[9]->available()){
            for (int i = 0; i < 7; i++) {
                if (materials[i] == 0){
                    materials[i] = 9;
                    productList[9]->remove(1);
                    muFactory->PlayChunk(Music::cSELECT);
                    break;
                }
            }
        }
    }else if (x <= 128 && x >= 0 && y <= 488 && y >= 372 && mouseL){
        if (productList[10]->available()){
            for (int i = 0; i < 7; i++) {
                if (materials[i] == 0){
                    materials[i] = 10;
                    productList[10]->remove(1);
                    muFactory->PlayChunk(Music::cSELECT);
                    break;
                }
            }
        }
    }else if (x <= 256 && x >= 128 && y <= 488 && y >= 372 && mouseL){
        if (productList[11]->available()){
            for (int i = 0; i < 7; i++) {
                if (materials[i] == 0){
                    materials[i] = 11;
                    productList[11]->remove(1);
                    muFactory->PlayChunk(Music::cSELECT);
                    break;
                }
            }
        }
    }else if (x <= 384 && x >= 256 && y <= 488 && y >= 372 && mouseL){
        if (productList[12]->available()){
            for (int i = 0; i < 7; i++) {
                if (materials[i] == 0){
                    materials[i] = 12;
                    productList[12]->remove(1);
                    muFactory->PlayChunk(Music::cSELECT);
                    break;
                }
            }
        }
    }else if (x <= 512 && x >= 384 && y <= 488 && y >= 372 && mouseL){
        if (productList[13]->available()){
            for (int i = 0; i < 7; i++) {
                if (materials[i] == 0){
                    materials[i] = 13;
                    productList[13]->remove(1);
                    muFactory->PlayChunk(Music::cSELECT);
                    break;
                }
            }
        }
    }else if (x <= 640 && x >= 512 && y <= 488 && y >= 372 && mouseL){
        if (productList[14]->available()){
            for (int i = 0; i < 7; i++) {
                if (materials[i] == 0){
                    materials[i] = 14;
                    productList[14]->remove(1);
                    muFactory->PlayChunk(Music::cSELECT);
                    break;
                }
            }
        }
    }else if (x <= 768 && x >= 640 && y <= 488 && y >= 372 && mouseL){
        if (productList[15]->available()){
            for (int i = 0; i < 7; i++) {
                if (materials[i] == 0){
                    materials[i] = 15;
                    productList[15]->remove(1);
                    muFactory->PlayChunk(Music::cSELECT);
                    break;
                }
            }
        }
    }else if (x <= 896 && x >= 768 && y <= 488 && y >= 372 && mouseL){
        if (productList[16]->available()){
            for (int i = 0; i < 7; i++) {
                if (materials[i] == 0){
                    materials[i] = 16;
                    productList[16]->remove(1);
                    muFactory->PlayChunk(Music::cSELECT);
                    break;
                }
            }
        }
    }else if (x <= 1024 && x >= 896 && y <= 488 && y >= 372 && mouseL){
        if (productList[17]->available()){
            for (int i = 0; i < 7; i++) {
                if (materials[i] == 0){
                    materials[i] = 17;
                    productList[17]->remove(1);
                    muFactory->PlayChunk(Music::cSELECT);
                    break;
                }
            }
        }
    }else if (x <= 1152 && x >= 1024 && y <= 488 && y >= 372 && mouseL){
        if (productList[18]->available()){
            for (int i = 0; i < 7; i++) {
                if (materials[i] == 0){
                    materials[i] = 18;
                    productList[18]->remove(1);
                    muFactory->PlayChunk(Music::cSELECT);
                    break;
                }
            }
        }
    }else if (x <= 1280 && x >= 1152 && y <= 488 && y >= 372 && mouseL){
        if (productList[19]->available()){
            for (int i = 0; i < 7; i++) {
                if (materials[i] == 0){
                    materials[i] = 19;
                    productList[19]->remove(1);
                    muFactory->PlayChunk(Music::cSELECT);
                    break;
                }
            }
        }
    }else if (x <= 128 && x >= 0 && y <= 604 && y >= 488 && mouseL){
        if (productList[20]->available()){
            for (int i = 0; i < 7; i++) {
                if (materials[i] == 0){
                    materials[i] = 20;
                    productList[20]->remove(1);
                    muFactory->PlayChunk(Music::cSELECT);
                    break;
                }
            }
        }
    }else if (x <= 256 && x >= 128 && y <= 604 && y >= 488 && mouseL){
        if (productList[21]->available()){
            for (int i = 0; i < 7; i++) {
                if (materials[i] == 0){
                    materials[i] = 21;
                    productList[21]->remove(1);
                    muFactory->PlayChunk(Music::cSELECT);
                    break;
                }
            }
        }
    }else if (x <= 384 && x >= 256 && y <= 604 && y >= 488 && mouseL){
        if (productList[22]->available()){
            for (int i = 0; i < 7; i++) {
                if (materials[i] == 0){
                    materials[i] = 22;
                    productList[22]->remove(1);
                    muFactory->PlayChunk(Music::cSELECT);
                    break;
                }
            }
        }
    }else if (x <= 512 && x >= 384 && y <= 604 && y >= 488 && mouseL){
        if (productList[23]->available()){
            for (int i = 0; i < 7; i++) {
                if (materials[i] == 0){
                    materials[i] = 23;
                    productList[23]->remove(1);
                    muFactory->PlayChunk(Music::cSELECT);
                    break;
                }
            }
        }
    }else if (x <= 640 && x >= 512 && y <= 604 && y >= 488 && mouseL){
        if (productList[24]->available()){
            for (int i = 0; i < 7; i++) {
                if (materials[i] == 0){
                    materials[i] = 24;
                    productList[24]->remove(1);
                    muFactory->PlayChunk(Music::cSELECT);
                    break;
                }
            }
        }
    }else if (x <= 768 && x >= 640 && y <= 604 && y >= 488 && mouseL){
        if (productList[25]->available()){
            for (int i = 0; i < 7; i++) {
                if (materials[i] == 0){
                    materials[i] = 25;
                    productList[25]->remove(1);
                    muFactory->PlayChunk(Music::cSELECT);
                    break;
                }
            }
        }
    }else if (x <= 896 && x >= 768 && y <= 604 && y >= 488 && mouseL){
        if (productList[26]->available()){
            for (int i = 0; i < 7; i++) {
                if (materials[i] == 0){
                    materials[i] = 26;
                    productList[26]->remove(1);
                    muFactory->PlayChunk(Music::cSELECT);
                    break;
                }
            }
        }
    }else if (x <= 1024 && x >= 896 && y <= 604 && y >= 488 && mouseL){
        if (productList[27]->available()){
            for (int i = 0; i < 7; i++) {
                if (materials[i] == 0){
                    materials[i] = 27;
                    productList[27]->remove(1);
                    muFactory->PlayChunk(Music::cSELECT);
                    break;
                }
            }
        }
    }else if (x <= 1152 && x >= 1024 && y <= 604 && y >= 488 && mouseL){
        if (productList[28]->available()){
            for (int i = 0; i < 7; i++) {
                if (materials[i] == 0){
                    materials[i] = 28;
                    productList[28]->remove(1);
                    muFactory->PlayChunk(Music::cSELECT);
                    break;
                }
            }
        }
    }else if (x <= 1280 && x >= 1152 && y <= 604 && y >= 488 && mouseL){
        if (productList[29]->available()){
            for (int i = 0; i < 7; i++) {
                if (materials[i] == 0){
                    materials[i] = 29;
                    productList[29]->remove(1);
                    muFactory->PlayChunk(Music::cSELECT);
                    break;
                }
            }
        }
    }else if (x <= 128 && x >= 0 && y <= 720 && y >= 604 && mouseL){
        if (productList[30]->available()){
            for (int i = 0; i < 7; i++) {
                if (materials[i] == 0){
                    materials[i] = 30;
                    productList[30]->remove(1);
                    muFactory->PlayChunk(Music::cSELECT);
                    break;
                }
            }
        }
    }else if (x <= 256 && x >= 128 && y <= 720 && y >= 604 && mouseL){
        if (productList[31]->available()){
            for (int i = 0; i < 7; i++) {
                if (materials[i] == 0){
                    materials[i] = 31;
                    productList[31]->remove(1);
                    muFactory->PlayChunk(Music::cSELECT);
                    break;
                }
            }
        }
    }else if (x <= 384 && x >= 256 && y <= 720 && y >= 604 && mouseL){
        if (productList[32]->available()){
            for (int i = 0; i < 7; i++) {
                if (materials[i] == 0){
                    materials[i] = 32;
                    productList[32]->remove(1);
                    muFactory->PlayChunk(Music::cSELECT);
                    break;
                }
            }
        }
    }else if (x <= 512 && x >= 384 && y <= 720 && y >= 604 && mouseL){
        if (productList[33]->available()){
            for (int i = 0; i < 7; i++) {
                if (materials[i] == 0){
                    materials[i] = 33;
                    productList[33]->remove(1);
                    muFactory->PlayChunk(Music::cSELECT);
                    break;
                }
            }
        }
    }else if (x <= 640 && x >= 512 && y <= 720 && y >= 604 && mouseL){
        if (productList[34]->available()){
            for (int i = 0; i < 7; i++) {
                if (materials[i] == 0){
                    materials[i] = 34;
                    productList[34]->remove(1);
                    muFactory->PlayChunk(Music::cSELECT);
                    break;
                }
            }
        }
    }else if (x <= 768 && x >= 640 && y <= 720 && y >= 604 && mouseL){
        if (productList[35]->available()){
            for (int i = 0; i < 7; i++) {
                if (materials[i] == 0){
                    materials[i] = 35;
                    productList[35]->remove(1);
                    muFactory->PlayChunk(Music::cSELECT);
                    break;
                }
            }
        }
    }else if (x <= 896 && x >= 768 && y <= 720 && y >= 604 && mouseL){
        if (productList[36]->available()){
            for (int i = 0; i < 7; i++) {
                if (materials[i] == 0){
                    materials[i] = 36;
                    productList[36]->remove(1);
                    muFactory->PlayChunk(Music::cSELECT);
                    break;
                }
            }
        }
    }else if (x <= 1024 && x >= 896 && y <= 720 && y >= 604 && mouseL){
        if (productList[37]->available()){
            for (int i = 0; i < 7; i++) {
                if (materials[i] == 0){
                    materials[i] = 37;
                    productList[37]->remove(1);
                    muFactory->PlayChunk(Music::cSELECT);
                    break;
                }
            }
        }
    }else if (x <= 1152 && x >= 1024 && y <= 720 && y >= 604 && mouseL){
        if (productList[38]->available()){
            for (int i = 0; i < 7; i++) {
                if (materials[i] == 0){
                    materials[i] = 38;
                    productList[38]->remove(1);
                    muFactory->PlayChunk(Music::cSELECT);
                    break;
                }
            }
        }
    }else if (x <= 1280 && x >= 1152 && y <= 720 && y >= 604 && mouseL){
        if (productList[39]->available()){
            for (int i = 0; i < 7; i++) {
                if (materials[i] == 0){
                    materials[i] = 39;
                    productList[39]->remove(1);
                    muFactory->PlayChunk(Music::cSELECT);
                    break;
                }
            }
        }
    }
    // ============
    // click output
    // ============
    if (x <= 1280 && x >= 1162 && y <= 226 && y >= 100 && mouseL){
        productList[output]->add(1);
        s->ACHIEVEMENTARRAY[output].add(status);
        output = 0;
        muFactory->PlayChunk(Music::cGETPRODUCT);
    }
    // ==========
    // click make
    // ==========
    if (x <= 1280 && x >= 1152 && y <= 372 && y >= 256)
        bigornot[1]=true;
    else
        bigornot[1]=false;
    
    if (x <= 1280 && x >= 1152 && y <= 372 && y >= 256 && mouseL) {
        sort(materials, materials + 7);
        string mat;
        for (int i = 0; i < 7; i++) {
            mat += to_string(materials[i]);
        }
        if (mat == vecA && workInProgress.size() < INPROGRESS_MAX){
            exp = 100;
            workInProgress.enqueue(wip(4, 1));  // go into progress
            muFactory->PlayChunk(Music::cPRODUCTOUT);
        }else if(mat == vecB && workInProgress.size() < INPROGRESS_MAX){
            exp = 100;
            workInProgress.enqueue(wip(9, 1));
            muFactory->PlayChunk(Music::cPRODUCTOUT);
        }else if(mat == vecC && workInProgress.size() < INPROGRESS_MAX){
            exp = 100;
            workInProgress.enqueue(wip(12, 1));
            muFactory->PlayChunk(Music::cPRODUCTOUT);
        }else if(mat == vecD && workInProgress.size() < INPROGRESS_MAX){
            exp = 100;
            workInProgress.enqueue(wip(15, 1));
            muFactory->PlayChunk(Music::cPRODUCTOUT);
        }else if(mat == vecE && workInProgress.size() < INPROGRESS_MAX){
            exp = 100;
            workInProgress.enqueue(wip(16, 1));
            muFactory->PlayChunk(Music::cPRODUCTOUT);
        }else if(mat == vecF && workInProgress.size() < INPROGRESS_MAX){
            exp = 100;
            workInProgress.enqueue(wip(17, 1));
            muFactory->PlayChunk(Music::cPRODUCTOUT);
        }else if(mat == vecG && workInProgress.size() < INPROGRESS_MAX){
            exp = 100;
            workInProgress.enqueue(wip(18, 1));
            muFactory->PlayChunk(Music::cPRODUCTOUT);
        }else if(mat == vecH && workInProgress.size() < INPROGRESS_MAX){
            exp = 100;
            workInProgress.enqueue(wip(20, 1));
            muFactory->PlayChunk(Music::cPRODUCTOUT);
        }else if(mat == vecI && workInProgress.size() < INPROGRESS_MAX){
            exp = 100;
            workInProgress.enqueue(wip(21, 1));
            muFactory->PlayChunk(Music::cPRODUCTOUT);
        }else if(mat == vecJ && workInProgress.size() < INPROGRESS_MAX){
            exp = 100;
            workInProgress.enqueue(wip(24, 1));
            muFactory->PlayChunk(Music::cPRODUCTOUT);
        }else if(mat == vecK && workInProgress.size() < INPROGRESS_MAX){
            exp = 100;
            workInProgress.enqueue(wip(25, 1));
            muFactory->PlayChunk(Music::cPRODUCTOUT);
        }else if(mat == vecL && workInProgress.size() < INPROGRESS_MAX){
            exp = 100;
            workInProgress.enqueue(wip(28, 1));
            muFactory->PlayChunk(Music::cPRODUCTOUT);
        }else if(mat == vecM && workInProgress.size() < INPROGRESS_MAX){
            exp = 100;
            workInProgress.enqueue(wip(29, 1));
            muFactory->PlayChunk(Music::cPRODUCTOUT);
        }else if(mat == vecN && workInProgress.size() < INPROGRESS_MAX){
            exp = 100;
            workInProgress.enqueue(wip(30, 1));
            muFactory->PlayChunk(Music::cPRODUCTOUT);
        }else if(mat == vecO && workInProgress.size() < INPROGRESS_MAX){
            exp = 100;
            workInProgress.enqueue(wip(33, 1));
            muFactory->PlayChunk(Music::cPRODUCTOUT);
        }else if(mat == vecP && workInProgress.size() < INPROGRESS_MAX){
            exp = 100;
            workInProgress.enqueue(wip(34, 1));
            muFactory->PlayChunk(Music::cPRODUCTOUT);
        }else if(mat == vecQ && workInProgress.size() < INPROGRESS_MAX){
            exp = 100;
            workInProgress.enqueue(wip(36, 1));
            muFactory->PlayChunk(Music::cPRODUCTOUT);
        }else if(mat == vecR && workInProgress.size() < INPROGRESS_MAX){
            exp = 100;
            workInProgress.enqueue(wip(38, 1));
            muFactory->PlayChunk(Music::cPRODUCTOUT);
        }else if(mat == vecS && workInProgress.size() < INPROGRESS_MAX){
            exp = 100;
            workInProgress.enqueue(wip(39, 1));
            muFactory->PlayChunk(Music::cPRODUCTOUT);
        }else{
            exp = 0;
            for (int i = 0; i < 7; ++i){
                productList[materials[i]]->add(1);
                muFactory->PlayChunk(Music::cWRONG);
            }
        }
        mat.clear();
        for (int i = 0; i < 7; i++) {
            materials[i] = 0;
        }
    }
    return exp;
}
void Factory::readImage(SDL_Renderer *rR)
{
    tFactory = new Texture[12];
    for (int i = 0; i < 10; i++) {
        tFactory->LoadImagePNG("num_" + to_string(i), rR);
    }
    tFactory->LoadImagePNG("factorybg", rR);
    tFactory->LoadImagePNG("clickAbove", rR);
    tFactory->LoadImagePNG("notGot", rR);
    tFactory->LoadImagePNG("make", rR);
}
void Factory::drawFactory(SDL_Renderer* rR, bool f)
{
    // background
    tFactory->Draw(rR, 0, 0, 720, 1280, 0, 0, 10);
    
    // materials
    for (int i = 0; i < 7; i++) {
        if (i == 7)
            break;
        if (materials[i] != 0)
            productList[materials[i]]->drawProduct(rR, 15+(116*i), 113, 90, 90);
    }
    
    // workInProgress
    for (int i = 0; i < workInProgress.size(); ++i)
    {
        int index = workInProgress[i].index;
        productList[index]->drawProduct(rR, 15+(116*(9-i)), 113, 90, 90);
    }
    
    // output
    if (output != 0){
        int x=0;
        if(bigornot[0])
            x+=20;
        
        productList[output]->drawProduct(rR, 1175-x/2, 113-x/2, 90+x, 90+x);
        tFactory->Draw(rR, 0, 0, 40, 80, 1180, 216, 11);
    }
    // product num
    for (int i = 1; i < 10; i++) {
        if (!productList[i]->isGot()){  // if not got
            tFactory->Draw(rR, 0, 0, 90, 90, 13+128*(i-1), 269, 12);
        }
        int num3 = productList[i]->onHand();
        if (num3 >= 100){
            int num1 = num3 / 100;
            num3 -= num1*100;
            tFactory->Draw(rR, 0, 0, 32, 32, 38+128*(i-1), 340, num1);
        }
        if (num3 >= 10){
            int num2 = num3 / 10;
            num3 -= num2*10;
            tFactory->Draw(rR, 0, 0, 32, 32, 58+128*(i-1), 340, num2);
        }
        tFactory->Draw(rR, 0, 0, 32, 32, 88+128*(i-1), 340, num3);
    }
    
    for (int i = 1; i < 4; i++) {
        for (int j = 0; j < 10; j++) {
            if (!productList[10*i+j]->isGot()){  // if not got
                tFactory->Draw(rR, 0, 0, 90, 90, 13+128*j, 269 + 116*i, 12);
            }
            int num3 = productList[10*i + j]->onHand();
            if (num3 >= 100){
                int num1 = num3 / 100;
                num3 -= num1*100;
                tFactory->Draw(rR, 0, 0, 32, 32, 38+128*j, 340+116*i, num1);
            }
            if (num3 >= 10){
                int num2 = num3 / 10;
                num3 -= num2*10;
                tFactory->Draw(rR, 0, 0, 32, 32, 58+128*j, 340+116*i, num2);
            }
            tFactory->Draw(rR, 0, 0, 32, 32, 88+128*j, 340+116*i, num3);
        }
    }
    // end of products drawing
    if(bigornot[1])
        tFactory->Draw(rR, 0, 0, 123, 136, 1149, 251, 13);
}






