//
//  Music.h
//  HappyFarm
//
//  Created by YenJung on 2018/7/8.
//  Copyright © 2018年 YenJung. All rights reserved.
//

#ifndef Music_h
#define Music_h

#include <SDL2/SDL.h>
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "LinkedList.h"
#include <string>
#include <iostream>

using namespace std;

class Music
{
public:
    Music();
    ~Music();
    
    bool musicStopped;
    
    enum eMusic{
        mNOTHING,
        mMENU,
        mFIELD,
        mFACTORY,
        mFEEDFACTORY,
        mSHOP,
        mANIMALFARM,
        mORDER,
        mACHIEVEMENT,
    };
    
    eMusic currentMusic;
    
    enum eChunk{
        cBUY,
        cCHICKEN,
        cCOW,
        cHARVEST,
        cNOTREACH,
        cPIG,
        cPRODUCTOUT,
        cREACH,
        cRESET,
        cSEEDSET,
        cSELECT,
        cSTATUS,
        cWRONG,
        cZOMBIE,
        cLEVELUP,
        cEXP,
        cGETPRODUCT,
        cNOFEED,
    };
    
    void changeMusic(bool musicByLevel, bool forceChange);
    
    void PlayMusic();
    void PlayMusic(eMusic musicID);
    void StopMusic();
    void PauseMusic();
    
    void PlayChunk(eChunk chunkID);
    static Mix_Music* loadMusic(string filename);
    static Mix_Chunk* loadChunk(string filename);
    
    int getVolume();
    void setVolume(int iVolume);
    
    static LinkedList< Mix_Music*> aMusic; //  all music
    static LinkedList< Mix_Chunk*> aSFX;   //  all sound effects
    
private:
    int iVolume;
};
#endif /* Music_h */


