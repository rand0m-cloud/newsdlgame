#pragma once
#include "Sprite.h"
#include <SDL2/SDL.h>
#include <iostream>
class ImageSprite : public Sprite {
private:
  std::string gFilename;

public:
  ImageSprite(SDL_Renderer *, std::string);
  void createTexture();
  ~ImageSprite();
};