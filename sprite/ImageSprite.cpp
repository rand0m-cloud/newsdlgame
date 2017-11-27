#include "ImageSprite.h"
#include "../color.h"
#include "../logging.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

ImageSprite::ImageSprite(SDL_Renderer *mRenderer, std::string filename)
    : Sprite(mRenderer), gFilename(filename) {
  gTexture = IMG_LoadTexture(gRender, gFilename.c_str());
  if (gTexture == NULL) {
    ERROR("gTexture is null");
    ERROR(SDL_GetError());
  }
  SDL_QueryTexture(gTexture, NULL, NULL, &sourceRect.w, &sourceRect.h);
}
void ImageSprite::createTexture() {
  // texture does not change
  return;
}
