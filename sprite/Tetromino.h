#pragma once
#include "Mino.h"
#include "Shapes.h"
#include <SDL2/SDL.h>
#include <vector>
class Tetromino : public Sprite {

public:
  enum Shape { O = 0, I, T, L, J, S, Z };
  enum Rotation { CW = 0, CCW };
  Tetromino(SDL_Renderer *renderer, enum Shape type, int startX, int startY);
  virtual ~Tetromino();
  void createTexture();
  bool moveDown();
  bool rotate(enum Rotation);
  void render(int milli, SDL_Texture *targetTexture);
  bool isActive = false;
  std::vector<Mino *> minos;

private:
  TetrominoPattern const *gPattern;
  enum Tetromino::Shape gType;
};
