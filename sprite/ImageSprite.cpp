#include "ImageSprite.h"
#include "../color.h"
#include "../logging.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

ImageSprite::ImageSprite(SDL_Renderer *mRenderer, std::string filename)
    : Sprite(mRenderer) {
  changeImage(filename);
}
ImageSprite::ImageSprite(SDL_Renderer *mRenderer) : Sprite(mRenderer) {}
void ImageSprite::createTexture() {
  // texture does not change
  return;
}
void ImageSprite::changeImage(std::string filename) {
  gFilename = filename;
  gTexture = IMG_LoadTexture(gRender, gFilename.c_str());
  if (gTexture == NULL) {
    ERROR("gTexture is null");
    ERROR(SDL_GetError());
  }
  SDL_QueryTexture(gTexture, NULL, NULL, &sourceRect.w, &sourceRect.h);
}
ImageSprite::~ImageSprite() {}
