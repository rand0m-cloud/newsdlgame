#pragma once
#include "../collision/CollisionGroup.h"
#include "Mino.h"
#include "Shapes.h"
#include "Sprite.h"
#include <SDL2/SDL.h>
#include <vector>
class Tetromino : public Sprite, public CollisionGroup {

public:
  enum Shape { O = 0, I, T, L, J, S, Z };
  Tetromino(SDL_Renderer *renderer, enum Shape type, int startX, int startY);
  virtual ~Tetromino();
  void createTexture();
  bool moveDown();
  void render(int milli, SDL_Texture *targetTexture);
  bool isActive = false;
  std::vector<Mino *> minos;

private:
  TetrominoPattern const *gPattern;
  enum Tetromino::Shape gType;
};
