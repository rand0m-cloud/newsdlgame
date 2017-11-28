#pragma once
#include "ImageSprite.h"
#include <SDL2/SDL.h>
class Mino : public ImageSprite {

public:
  enum Color { cyan, yellow, purple, green, red, lightblue, darkblue, orange };
  Mino(SDL_Renderer *, enum Color);
  ~Mino();
  SDL_Texture *render(int millis);

private:
  enum Mino::Color gColor;
};
