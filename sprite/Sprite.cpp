#include <SDL2/SDL.h>
#include "Sprite.h"
#include <iostream>

Sprite::Sprite(SDL_Renderer* mRender) : gRender(mRender){
    gTexture = SDL_CreateTexture(gRender,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_STATIC,sourceRect.w,sourceRect.h);
    
}
Sprite::~Sprite(){
    if(gTexture!=NULL)
        SDL_DestroyTexture(gTexture);
}
void Sprite::createTexture(){
    SDL_SetRenderTarget(gRender,gTexture);
    SDL_SetRenderDrawColor(gRender,gColor.r,gColor.g,gColor.b,gColor.a);
    SDL_RenderFillRect(gRender,&sourceRect);
    
}
SDL_Texture* Sprite::render(){
    createTexture();
    return gTexture;
}

