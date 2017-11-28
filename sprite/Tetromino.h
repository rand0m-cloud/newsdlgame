#pragma once
#include "Mino.h"
#include "Shapes.h"
#include "Sprite.h"
#include <SDL2/SDL.h>
#include <vector>
class Tetromino : public Sprite {

public:
  enum Shape { O, I, T, L, J, S, Z };
  Tetromino(SDL_Renderer *renderer, enum Shape type, int startX, int startY);
  virtual ~Tetromino();
  void createTexture();

private:
  std::vector<Mino *> minos;
  TetrominoPattern const *gPattern;
  enum Tetromino::Shape gType;
};
