//
//  Texture.cpp
//  HAPPYFARM
//
//  Created by HowARD-001 on 2018/6/11.
//  Copyright © 2018年 HowARD-001. All rights reserved.
//

#include "Texture.h"
Texture::Texture()
{
}

Texture::~Texture()
{
    for (int i = 0, n = images.getLengh(); i < n; ++i) {
        SDL_DestroyTexture(images[i+1]);
    }
}

void
Texture::Draw(SDL_Renderer * rR, int iXOffset, int iYOffset,int h,int w, int iFrame)
{
    rRect.x = iXOffset;
    rRect.y = iYOffset;
    rRect.h=h;
    rRect.w=w;
    
    SDL_RenderCopy(rR, images[iFrame+1], &rRect, &rRect);
}

void
Texture::Draw(SDL_Renderer * rR, int iXOffset, int iYOffset,int h,int w, int x,int y,int iFrame)
{
    srcRect.x = iXOffset;
    srcRect.y = iYOffset;
    srcRect.h = h;
    srcRect.w =w;
    rRect.x = x;
    rRect.y = y;
    rRect.h = h;
    rRect.w = w;
    
    SDL_RenderCopy(rR, images[iFrame+1], &srcRect, &rRect);
}

void
Texture::Draw(SDL_Renderer * rR, int iXOffset, int iYOffset, int iFrame)
{
    rRect.x = iXOffset;
    rRect.y = iYOffset;
    
    SDL_RenderCopy(rR, images[iFrame+1], NULL, &rRect);
}

void
Texture::LoadImageBMP(string fileName, SDL_Renderer * rR)
{
    cout << "load " << fileName << "\n";
    fileName = "res/" + fileName + ".bmp";
    SDL_Surface* loadedSurface = SDL_LoadBMP(fileName.c_str());
    
    SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 255, 0, 255));
    
    SDL_Texture* tIMG = SDL_CreateTextureFromSurface(rR, loadedSurface);
    int iWidth, iHeight;
    
    SDL_QueryTexture(tIMG, NULL, NULL, &iWidth, &iHeight);
    
    rRect.x  = 0;
    rRect.y = 0;
    rRect.w = iWidth;
    rRect.h = iHeight;
    SDL_FreeSurface(loadedSurface);
    
    images.push(tIMG);
}

void
Texture::LoadImagePNG(string fileName, SDL_Renderer * rR)
{
    cout << "load " << fileName << "\n";
    fileName = "res/image/" + fileName + ".png";
    SDL_Surface* loadedSurface = IMG_Load(fileName.c_str());
    
    if(loadedSurface==nullptr)
        cout<<"error\n";
    
    SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 255, 0, 255));
    
    SDL_Texture* tIMG = SDL_CreateTextureFromSurface(rR, loadedSurface);
    int iWidth, iHeight;
    
    SDL_QueryTexture(tIMG, NULL, NULL, &iWidth, &iHeight);
    
    rRect.x  = 0;
    rRect.y = 0;
    rRect.w = iWidth;
    rRect.h = iHeight;
    SDL_FreeSurface(loadedSurface);
    
    images.push(tIMG);
    
}

void
Texture::LoadImage(string fileName, SDL_Renderer * rR)
{
    
    
    SDL_Surface* loadedSurface = IMG_Load(fileName.c_str());
    
    if(loadedSurface==nullptr)
        cout<<"error\n";
    
    SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 255, 0, 255));
    
    SDL_Texture* tIMG = SDL_CreateTextureFromSurface(rR, loadedSurface);
    int iWidth, iHeight;
    
    SDL_QueryTexture(tIMG, NULL, NULL, &iWidth, &iHeight);
    
    
    rRect.x  = 0;
    rRect.y = 0;
    rRect.w = iWidth;
    rRect.h = iHeight;
    SDL_FreeSurface(loadedSurface);
    
    images.push(tIMG);
    
}

void Texture::print(string textureText, const SDL_Color textColor, int x,int y, TTF_Font* font , SDL_Renderer * rR)
{
    
    //Render text surface
    SDL_Surface* textSurface = TTF_RenderText_Solid( font, textureText.c_str(), textColor );
    SDL_Texture* mTexture = NULL;
    if( textSurface == NULL )
    {
        printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
    }
    else
    {
        //Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface( rR, textSurface );
        if( mTexture == NULL )
        {
            printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
        }
        else
        {
            rRect.x = x;
            rRect.y = y;
        }
        
        //Get rid of old surface
        SDL_FreeSurface( textSurface );
    }
    
    //Return success
    SDL_RenderCopy(rR, mTexture, NULL, &rRect);
}


