#pragma once
#include <SDL2/SDL.h>
#include "../color.h"
class Sprite{
    private:
        SDL_Renderer* gRender;
        SDL_Texture* gTexture;
    public:
        Sprite(SDL_Renderer*);
        ~Sprite();
        SDL_Texture* render();
        SDL_Rect sourceRect = {0,0,100,100};
        void createTexture();
        SDL_Rect dstRect = {0,0,100,100};
        color gColor = WHITE;
};