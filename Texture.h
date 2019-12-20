/***********************************************************************
 <                 IMPD Final Project -  BomberMan                    >
 FileName     [ Texture.h ]
 Authors      [ Yi-Ting Lin, Yu-Lung Hsiao, Hao Cheng, Yen-Jung Hsu ]
 Date         [ 2017/12/31 created ]
 ***********************************************************************/

#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>
#include "LinkedList.h"
#include "SDL2/SDL_ttf.h"



using namespace std;

class Texture
{
public:
    Texture();
    ~Texture();
    
    void Draw(SDL_Renderer * rR, int iXOffset, int iYOffset, int iFrame = 0);
    void Draw(SDL_Renderer * rR, int iXOffset, int iYOffset,int h,int w, int iFrame = 0);
    void Draw(SDL_Renderer * rR, int iXOffset, int iYOffset,int h,int w, int x,int y,int iFrame);
    
    void LoadImageBMP(string fileName, SDL_Renderer * rR);
    void LoadImagePNG(string fileName, SDL_Renderer * rR);
    void LoadImage(string fileName, SDL_Renderer * rR);
    
    
    void print(string textureText, const SDL_Color textColor, int x,int y, TTF_Font* font , SDL_Renderer * rR);
    
    
private:
    //   vector<SDL_Texture*> images;
    LinkedList<SDL_Texture*> images;
    SDL_Rect rRect;
    SDL_Rect srcRect;
    
};

#endif //_BLOCK_H_


