#include "Sprite.h"
#include "../color.h"
#include <SDL2/SDL.h>
#include <iostream>

Sprite::Sprite(SDL_Renderer *mRender) : gRender(mRender) {
  gTexture =
      SDL_CreateTexture(gRender, SDL_PIXELFORMAT_RGBA8888,
                        SDL_TEXTUREACCESS_TARGET, sourceRect.w, sourceRect.h);
  x = &dstRect.x;
  y = &dstRect.y;
  w = &dstRect.w;
  h = &dstRect.h;
}
Sprite::~Sprite() {
  if (gTexture != NULL)
    SDL_DestroyTexture(gTexture);
}
void Sprite::createTexture() {
  SDL_SetRenderTarget(gRender, gTexture);
  SDL_SetRenderDrawColor(gRender, RED.r, RED.g, RED.b, RED.a);
  SDL_RenderFillRect(gRender, &sourceRect);
}
SDL_Texture *Sprite::render(int milli) {
  createTexture();
  return gTexture;
}
