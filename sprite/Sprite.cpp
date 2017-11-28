#include "Sprite.h"
#include "../color.h"
#include <SDL2/SDL.h>
#include <iostream>

Sprite::Sprite(SDL_Renderer *mRender) : gRender(mRender) {
  x = &dstRect.x;
  y = &dstRect.y;
  w = &dstRect.w;
  h = &dstRect.h;
}
Sprite::~Sprite() {
  if (gTexture != NULL)
    SDL_DestroyTexture(gTexture);
  gTexture = NULL;
}
void Sprite::createTexture() {
  if (gTexture == NULL)
    gTexture =
        SDL_CreateTexture(gRender, SDL_PIXELFORMAT_RGBA8888,
                          SDL_TEXTUREACCESS_TARGET, sourceRect.w, sourceRect.h);
  SDL_SetTextureBlendMode(gTexture, SDL_BLENDMODE_BLEND);
}
void Sprite::render(int milli, SDL_Texture *targetTexture) {
  createTexture();
  SDL_SetRenderTarget(gRender, targetTexture);
  SDL_RenderCopy(gRender, gTexture, &sourceRect, &dstRect);
}
