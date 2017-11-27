#pragma once
#include "ImageSprite.h"
#include <SDL2/SDL.h>
#include <iostream>
class Player : public ImageSprite {
private:


public:
  Player(SDL_Renderer* renderer, int startingX, int startingY);
  void createTexture();
  SDL_Texture* render();
};
