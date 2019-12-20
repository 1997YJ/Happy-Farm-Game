
#include "GameMgr.h"
#include "Texture.h"
#include "AnimalFarm.h"
#include "Music.h"

using namespace std;

int GameMgr::COMPUTER_SETTING = 1;
int GameMgr::TIME_SETTING = 2;

#define  GAME_WIDTH  1280
#define  GAME_HEIGHT 720
#define  UNIT_PIXEL  32

GameMgr::GameMgr()
{
    // Game Stat
    NowStat = INIT;
    this->quitGame = false;
    frameCounter = 0;
    
    // SDL
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO);
    
    window = SDL_CreateWindow("Farm", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, GAME_WIDTH, GAME_HEIGHT, SDL_WINDOW_SHOWN);
    
    if (window == NULL) {
        quitGame = true;
    }
    
    rR = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    mainEvent = new SDL_Event();
    
    // image
    initLoadIMG();
    
    // construction
    aAchievementArray = new AchievementArray(rR);
    aFactory = new Factory(rR);
    aFeedFactory = new FeedFactory(rR);
    aCondition = new Condition(rR, 5000, 0, 1);
    aOrder = new Order(rR);
    aStore = new Store(rR);
    aFarm = new Farm(aFactory);
    aFarm->initFarm(rR);
    
    aAnimalFarm = new AnimalFarm(aFactory,aAchievementArray,aCondition);
    aAnimalFarm->loadImage(rR); 
    
    
    // music
    initLoadMUS();
    
}


GameMgr::~GameMgr()
{
    delete mainEvent;
    SDL_DestroyRenderer(rR);
    SDL_DestroyWindow(window);
}

// init
void
GameMgr::initLoadIMG()
{
    gmTexture = new Texture[8];
    gmTexture->LoadImagePNG("menubg", rR);
    gmTexture->LoadImagePNG("StartDown", rR);
    gmTexture->LoadImagePNG("StartUp", rR);
    gmTexture->LoadImagePNG("CONTINUE", rR);
}


void
GameMgr::initLoadMUS()
{
    AchievementArray::muAchievementArray = new Music;
    Factory::muFactory = new Music;
    FeedFactory::muFeedFactory = new Music;
    Order::muOrder = new Music;
    Store::muStore = new Music;
    Farm::muFarm = new Music;
    muMenu = new Music;
    AnimalFarm::muAnimalFarm = new Music;
    
    //initalize SDL_mixer
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    
    //load all the music into aMusic vector
    Music::aMusic.push(Music::loadMusic("menu.wav"));
    Music::aMusic.push(Music::loadMusic("field.wav"));
    Music::aMusic.push(Music::loadMusic("factory.wav"));
    Music::aMusic.push(Music::loadMusic("feedfactory.wav"));
    Music::aMusic.push(Music::loadMusic("shop.wav"));
    Music::aMusic.push(Music::loadMusic("animalfarm.wav"));
    Music::aMusic.push(Music::loadMusic("order.wav"));
    Music::aMusic.push(Music::loadMusic("achievement.wav"));
    
    //load all the SFX into aChunk vector
    Music::aSFX.push(Music::loadChunk("buy.wav"));
    Music::aSFX.push(Music::loadChunk("chicken.wav"));
    Music::aSFX.push(Music::loadChunk("cow.wav"));
    Music::aSFX.push(Music::loadChunk("harvest.wav"));
    Music::aSFX.push(Music::loadChunk("notreach.wav"));
    Music::aSFX.push(Music::loadChunk("pig.wav"));
    Music::aSFX.push(Music::loadChunk("productout.wav"));
    Music::aSFX.push(Music::loadChunk("reach.wav"));
    Music::aSFX.push(Music::loadChunk("reset.wav"));
    Music::aSFX.push(Music::loadChunk("seedset.wav"));
    Music::aSFX.push(Music::loadChunk("select.wav"));
    Music::aSFX.push(Music::loadChunk("status.wav"));
    Music::aSFX.push(Music::loadChunk("wrong.wav"));
    Music::aSFX.push(Music::loadChunk("zombie.wav"));
    Music::aSFX.push(Music::loadChunk("levelup.wav"));
    Music::aSFX.push(Music::loadChunk("exp.wav"));
    Music::aSFX.push(Music::loadChunk("getproduct.wav"));
    Music::aSFX.push(Music::loadChunk("nofeed.wav"));
}



// Loop

void
GameMgr::mainLoop()
{
    
    while (!quitGame && mainEvent->type != SDL_QUIT)
    {
        frameTime = SDL_GetTicks(); // 2@?i //  =  second/1000
        // for debug test
        cout << frameTime / 1000 << endl;
        
        SDL_PollEvent(mainEvent);
        SDL_RenderClear(rR);
        
        // CCFG::getMM()->setBackgroundColor(rR);
        SDL_RenderFillRect(rR, NULL);
        
        MouseInput();
        Update();
        Draw();
        
        SDL_RenderPresent(rR);
        ++frameCounter;
    }
}


void
GameMgr::Update()
{
    switch (NowStat)
    {
        case INIT:
        {
            // init
            muMenu->PlayMusic(Music::mMENU);
            NowStat = MENU; // MENU;
            // menu = new Menu();
            //cout << "INIT -> MENU \n";
            break;
        }
        case MENU:
        {
            //muMenu->PlayMusic(Music::mMENU);
            gmTexture->Draw(rR, 0, 0, 720, 1280, 0, 0, 0);
            gmTexture->Draw(rR, 0, 0, 100, 300,490,420, 1);//START
//            gmTexture->Draw(rR, 0, 0, 100, 430,425,540, 3);//CONTINUE
            if((490 < mouseX) && (790 > mouseX) && (420 < mouseY) && (520 > mouseY) )
            {
                gmTexture->Draw(rR, 0, 0, 100, 300,490,420, 2);//STARTdown
                if(mouseLeftTrigger){
                    muMenu->PlayChunk(Music::cSELECT);
                    muMenu->StopMusic();
                    Farm::muFarm->PlayMusic(Music::mFIELD);
                    NowStat = FARM;
                }
            }
            break;
        }
        case FARM:
        {
            
            int stat = aFarm->update(mouseX, mouseY, mouseLeftTrigger,aAchievementArray,aCondition);
            int ctrl=aCondition->updateCondtion(mouseX, mouseY, mouseLeftTrigger);
            if(ctrl==1){
                stat=1;
            }
            
            switch (stat) {
                case 0:
                    NowStat = INIT;
                    Farm::muFarm->StopMusic();
                    break;
                case 1:
                    NowStat = MENU;
                    Farm::muFarm->StopMusic();
                    muMenu->PlayMusic(Music::mMENU);
                    break;
                case 2:
                    NowStat = FARM;
                    break;
                case 3:
                    NowStat = ANIMALFARM;
                    Farm::muFarm->StopMusic();
                    AnimalFarm::muAnimalFarm->PlayMusic(Music::mANIMALFARM);
                    break;
                case 4:
                    NowStat = ORDER;
                    Farm::muFarm->StopMusic();
                    Order::muOrder->PlayMusic(Music::mORDER);
                    break;
                case 5:
                    NowStat = STORE;
                    Farm::muFarm->StopMusic();
                    Store::muStore->PlayMusic(Music::mSHOP);
                    break;
                case 6:
                    NowStat = ACHIEVEMENT;
                    Farm::muFarm->StopMusic();
                    AchievementArray::muAchievementArray->PlayMusic(Music::mACHIEVEMENT);
                    break;
                case 7:
                    NowStat = FEEDFACTORY;
                    Farm::muFarm->StopMusic();
                    FeedFactory::muFeedFactory->PlayMusic(Music::mFEEDFACTORY);
                    break;
                    
                default:
                    NowStat = FACTORY;
                    Farm::muFarm->StopMusic();
                    Factory::muFactory->PlayMusic(Music::mFACTORY);
                    break;
            }
            break;
            
        }
        case ANIMALFARM:
        {
            
            aAnimalFarm->updateAnimalFarm(mouseX, mouseY, mouseLeftTrigger);
            int ctrl=aCondition->updateCondtion(mouseX, mouseY,
                                                mouseLeftTrigger);
            if(ctrl==1){
                NowStat = FARM;
                AnimalFarm::muAnimalFarm->StopMusic();
                Farm::muFarm->PlayMusic(Music::mFIELD);
            }
            break;
        }
        case ORDER:
        {
            
            aOrder->updateOrder(mouseX, mouseY, mouseLeftTrigger, aCondition,
                                aFactory->productList,aAchievementArray);
            
            int ctrl=aCondition->updateCondtion(mouseX, mouseY,
                                                mouseLeftTrigger);
            if(ctrl==1){
                NowStat = FARM;
                Order::muOrder->StopMusic();
                Farm::muFarm->PlayMusic(Music::mFIELD);
            }
            break;
        }
        case STORE:
        {
            
            aStore->updateStore(mouseX, mouseY, mouseLeftTrigger,aAchievementArray, aCondition, aFarm,aAnimalFarm);
            int ctrl=aCondition->updateCondtion(mouseX, mouseY,
                                                mouseLeftTrigger);
            if(ctrl==1){
                NowStat = FARM;
                Store::muStore->StopMusic();
                Farm::muFarm->PlayMusic(Music::mFIELD);
            }
            break;
        }
        case ACHIEVEMENT:
        {
            
            int temp = aCondition->updateCondtion(mouseX, mouseY, mouseLeftTrigger);
            if (temp == 1){
                NowStat = FARM;
                AchievementArray::muAchievementArray->StopMusic();
                Farm::muFarm->PlayMusic(Music::mFIELD);
            }
            break;
        }
        case FEEDFACTORY:
        {
            
            int exp2 = aFeedFactory->updateFeedFactory(mouseX, mouseY, mouseLeftTrigger,aCondition,aFactory->productList,aAchievementArray);
            aCondition->addExp(exp2);
            int temp2 = aCondition->updateCondtion(mouseX, mouseY, mouseLeftTrigger);
            if (temp2 == 1){
                NowStat = FARM;
                FeedFactory::muFeedFactory->StopMusic();
                Farm::muFarm->PlayMusic(Music::mFIELD);
            }
            break;
        }
        case FACTORY:
        {
            
            int exp = aFactory->updateFactory(mouseX, mouseY, mouseLeftTrigger,aAchievementArray,aCondition);
            aCondition->addExp(exp);
            int temp = aCondition->updateCondtion(mouseX, mouseY, mouseLeftTrigger);
            if (temp == 1){
                NowStat = FARM;
                Factory::muFactory->StopMusic();
                Farm::muFarm->PlayMusic(Music::mFIELD);
            }
            break;
        }
        default:
            break;
    }
}

void
GameMgr::Draw()
{
    // game mode
    if (NowStat == INIT)
    {
        
    }
    else if (NowStat == MENU)
    {
        
    }
    else if (NowStat == FARM)
    {
        aFarm->drawFarm(rR);
        aCondition->drawCondition(rR);
    }
    else if (NowStat == ANIMALFARM)
    {
        aAnimalFarm->drawAnimalFarm(rR);
        aCondition->drawCondition(rR);
    }
    else if (NowStat == ORDER)
    {
        aOrder->drawOrder(rR, aFactory->productList);
        aCondition->drawCondition(rR);
    }
    else if (NowStat == STORE)
    {
        aStore->drawStore(rR);
        aCondition->drawCondition(rR);
    }
    else if (NowStat == ACHIEVEMENT)
    {
        aAchievementArray->drawAchievement(rR);
        aCondition->drawCondition(rR);
    }
    else if (NowStat == FEEDFACTORY)
    {
        aFeedFactory->drawFeedFactory(rR, aFactory->productList);
        aCondition->drawCondition(rR);
    }
    else if (NowStat == FACTORY)
    {
        aFactory->drawFactory(rR, false);
        aCondition->drawCondition(rR);
    }
    if (NowStat == FARM)
    {
        aFarm->drawFarm(rR);
        aCondition->drawCondition(rR);
    }
}

void
GameMgr::MouseInput()
{
    mouseLeftTrigger = false;
    mouseRightTrigger = false;
    if (mainEvent->type == SDL_MOUSEBUTTONDOWN)
    {
        if (mainEvent->button.button == SDL_BUTTON_LEFT && !mouseLeftPressed) { mouseLeftPressed = true; cout << "Mouse L\n"; }
        else if (mainEvent->button.button == SDL_BUTTON_RIGHT && !mouseRightPressed) { mouseRightPressed = true; cout << "Mouse R\n"; }
    }
    else if (mainEvent->type == SDL_MOUSEBUTTONUP)
    {
        if (mainEvent->button.button == SDL_BUTTON_LEFT && mouseLeftPressed) { mouseLeftPressed = false; mouseLeftTrigger = true; }
        else if (mainEvent->button.button == SDL_BUTTON_RIGHT && mouseRightPressed) { mouseRightPressed = false; mouseRightTrigger = false; }
    }
    else if (mainEvent->type == SDL_MOUSEMOTION)
    {
        int x = mouseX, y = mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);
        if (x / 100 != mouseX / 100 || y / 100 != mouseY / 100) cout << mouseX << ", " << mouseY << endl;
        //if (x != mouseX || y != mouseY) cout << mouseX  <<", " << mouseY << endl;
    }
}


