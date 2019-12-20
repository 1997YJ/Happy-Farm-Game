#include <iostream>
using namespace std;
#include "Texture.h"
#include "Product.h"
#include "Factory.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
//#include "SDL2_ttf/SDL_ttf.h"
#include <stdio.h>
#include <string>

//Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
#include "Time.h"
#include "Animal.h"
#include "GameMgr.h"

//#include <iomanip>



int main(int argc, char* args[])  // int main(int argc, char* args[])
{
    
    Time game_time;
    game_time.Now();  // initialize to current time
    game_time.print();
    
    int exp;
    int money;
    time_t last_time; // data type : long int

    
    
    // start this game
    exp = 10;
    money = 22000;
    cout << setw(14) << "exp : " << exp << endl;
    cout << setw(14) << "money : " << money << endl;
    cout << setw(14) << "time passed : " << game_time.Now() - last_time << " seconds" << endl << endl;
    
    
    
    //    aChicken.getInfo();
    //    aCow.getInfo();
    //    aPig.getInfo();
    //    aZombie.getInfo();
    
    
    //
    //--------------------------------------------------------
    //
    
    GameMgr game;
    
    game.mainLoop();
    
    //
    //--------------------------------------------------------
    //
    
    
    
    
    
    
    
    //    while (true)
    //    {
    //        cout << "normal growing : ";
    //        aCow.grow();
    //    }
    
    
    // end this game
    
    game_time.Now();
    game_time.print();
    
    system("pause");
    return 0;
}

