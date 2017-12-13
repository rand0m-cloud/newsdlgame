#pragma once
#include "../collision/CollisionBase.h"
#include "ImageSprite.h"
#include <SDL2/SDL.h>
#define MINO_SIZE 20
class Mino : public ImageSprite, public CollisionBase {

public:
  enum Color { cyan, yellow, purple, green, red, lightblue, darkblue, orange };
  Mino(SDL_Renderer *, enum Color);
  ~Mino();
  void render(int milli, SDL_Texture *texture);
  SDL_Point gLocation;

private:
  enum Mino::Color gColor;
};
