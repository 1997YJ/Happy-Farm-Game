//
//  Music.cpp
//  HappyFarm
//
//  Created by YenJung on 2018/7/8.
//  Copyright © 2018年 YenJung. All rights reserved.
//


#include "Music.h"

LinkedList< Mix_Music*> Music::aMusic; //  all music
LinkedList< Mix_Chunk*> Music::aSFX;   //  all sound effects

Music::Music() {
    setVolume(100);
    this->currentMusic = mNOTHING;
}

//clean sounds
Music::~Music(){
    for(unsigned int i = 1; i < aMusic.getLengh()+1; i++){
        Mix_FreeMusic(aMusic[i]);
    }
    
    aMusic.clear();
    
    for(unsigned int i = 1; i < aSFX.getLengh()+1; i++){
        Mix_FreeChunk(aSFX[i]);
    }
    
    aSFX.clear();
}

//play currentmusic
void Music::PlayMusic(){
    if(currentMusic != mNOTHING){
        Mix_PlayMusic(aMusic[currentMusic], -1);
        musicStopped = false;
    }
    else{
        StopMusic();
    }
}

//play new music
void Music::PlayMusic(eMusic musicID){
    if(musicID != mNOTHING){
        Mix_PlayMusic(aMusic[musicID], -1);
        musicStopped = false;
        currentMusic = musicID;
    }
    else{
        StopMusic();
        currentMusic = mNOTHING;
    }
}

//stop music
void Music::StopMusic(){
    if(!musicStopped){
        Mix_HaltMusic();
        musicStopped = true;
    }
}

//pause or resume the music
void Music::PauseMusic(){
    //if music is stop resume the music
    if(Mix_PausedMusic() == 1){
        Mix_ResumeMusic();
        musicStopped = false;
    }
    //if music is playing stop the music
    else{
        Mix_PauseMusic();
        musicStopped = true;
    }
}

//play SFX
void Music::PlayChunk(eChunk chunkID){
    Mix_VolumeChunk(aSFX[chunkID+1], iVolume);
    Mix_PlayChannel(1, aSFX[chunkID+1], 0);
}

//load the music
Mix_Music* Music::loadMusic(string fileName){
    fileName = "res/sound/" + fileName;
    return Mix_LoadMUS(fileName.c_str());
}

//load the SFX
Mix_Chunk* Music::loadChunk(string fileName){
    fileName = "res/sound/" + fileName;
    return Mix_LoadWAV(fileName.c_str());
}

int Music::getVolume(){
    return iVolume;
}

//set the volume
void Music::setVolume(int iVolume){
    this->iVolume = iVolume;
    Mix_VolumeMusic(iVolume);
}





