#pragma once
#include "ImageSprite.h"
#include <SDL2/SDL.h>
#define MINO_SIZE 25
class Mino : public ImageSprite {

public:
  enum Color { cyan, yellow, purple, green, red, lightblue, darkblue, orange };
  Mino(SDL_Renderer *, enum Color);
  ~Mino();

private:
  enum Mino::Color gColor;
};
