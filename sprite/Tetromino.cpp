#include "Tetromino.h"
#include "../matrix/Matrix.h"
#include "Mino.h"
#include "Shapes.h"
#include <SDL2/SDL.h>

Tetromino::Tetromino(SDL_Renderer *mRenderer, enum Tetromino::Shape type,
                     int startX, int startY)
    : Sprite(mRenderer), CollisionGroup(), gType(type) {
  Mino::Color color;
  switch (gType) {
  case O:
    color = Mino::Color::yellow;
    gPattern = &O_SHAPE;
    break;
  case I:
    color = Mino::Color::lightblue;
    gPattern = &I_SHAPE;
    break;
  case T:
    color = Mino::Color::purple;
    gPattern = &T_SHAPE;
    break;
  case L:
    color = Mino::Color::orange;
    gPattern = &L_SHAPE;
    break;
  case J:
    color = Mino::Color::darkblue;
    gPattern = &J_SHAPE;
    break;
  case S:
    color = Mino::Color::green;
    gPattern = &S_SHAPE;
    break;
  case Z:
    color = Mino::Color::red;
    gPattern = &Z_SHAPE;
    break;
  default:
    ERROR("Switch defaulted");
    break;
  }
  sourceRect = dstRect;

  for (int i = 0; i < 4; i++) {
    Mino *m = new Mino(mRenderer, color);
    SDL_Point const *shape = &(*gPattern)[i];

    minos.push_back(m);
    addItem(m);
    m->gLocation = {startX + shape->x, startY + shape->y};
    if (Matrix::getInstance()->insertMino(m) == false) {
      DEBUG("Can not insert Mino");
    }
  }
  calculateRect();
}
Tetromino::~Tetromino() {}
void Tetromino::createTexture() { Sprite::createTexture(); }
void Tetromino::render(int milli, SDL_Texture *targetTexture) {

  if (isActive) {
    int dx = 0;
    int dy = 0;
    Uint8 const *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_W])
      dy = -1;
    if (state[SDL_SCANCODE_S])
      dy = 1;
    if (state[SDL_SCANCODE_A])
      dx = -1;
    if (state[SDL_SCANCODE_D])
      dx = 1;
    if (dx != 0 || dy != 0) {
      if (Matrix::getInstance()->tryMove(this, dx, dy))
        Matrix::getInstance()->move(this, dx, dy);
    }
  }

  for (Mino *m : minos) {
    m->render(milli, targetTexture);
  }
  calculateRect();

  visualize(gRender, targetTexture);
}
bool Tetromino::moveDown() {
  if (Matrix::getInstance()->tryMove(this, 0, 1) == false) {
    return false;
  }
  Matrix::getInstance()->move(this, 0, 1);
  return true;
}