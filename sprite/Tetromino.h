#pragma once
#include "Mino.h"
#include <SDL2/SDL.h>
#include <vector>
class Tetromino {

public:
  enum Shape { O, I, T, L, J, S, Z };
  Tetromino(SDL_Renderer *renderer, enum Shape type);
  virtual ~Tetromino();

private:
  std::vector<Mino *> minos;
  enum Tetromino::Shape gType;
};
