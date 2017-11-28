#include "Tetromino.h"
#include "Mino.h"
#include "Shapes.h"
#include <SDL2/SDL.h>

Tetromino::Tetromino(SDL_Renderer *mRenderer, enum Tetromino::Shape type,
                     int startX, int startY)
    : Sprite(mRenderer), gType(type) {
  Mino::Color color;
  switch (gType) {
  case O:
    color = Mino::Color::yellow;
    *w = 2 * MINO_SIZE;
    *h = 2 * MINO_SIZE;
    gPattern = &O_SHAPE;
    break;
  case I:
    color = Mino::Color::lightblue;
    *w = MINO_SIZE;
    *h = 4 * MINO_SIZE;
    gPattern = &I_SHAPE;
    break;
  case T:
    color = Mino::Color::purple;
    *w = 3 * MINO_SIZE;
    *h = 2 * MINO_SIZE;
    gPattern = &T_SHAPE;
    break;
  case L:
    color = Mino::Color::orange;
    *w = 2 * MINO_SIZE;
    *h = 3 * MINO_SIZE;
    gPattern = &L_SHAPE;
    break;
  case J:
    color = Mino::Color::darkblue;
    *w = 2 * MINO_SIZE;
    *h = 3 * MINO_SIZE;
    gPattern = &J_SHAPE;
    break;
  case S:
    color = Mino::Color::green;
    *w = 3 * MINO_SIZE;
    *h = 2 * MINO_SIZE;
    gPattern = &S_SHAPE;
    break;
  case Z:
    color = Mino::Color::red;
    *w = 3 * MINO_SIZE;
    *h = 2 * MINO_SIZE;
    gPattern = &Z_SHAPE;
    break;
  default:
    ERROR("Switch defaulted");
    break;
  }
  sourceRect = dstRect;
  *x = startX;
  *y = startY;
  for (int i = 0; i < 4; i++) {
    Mino *m = new Mino(mRenderer, color);
    SDL_Rect const *shape = &(*gPattern)[i];
    *m->x = shape->x;
    *m->y = shape->y;
    minos.push_back(m);
  }
}
Tetromino::~Tetromino() {}
void Tetromino::createTexture() {
  Sprite::createTexture();
  for (Mino *m : minos) {
    m->render(0, gTexture);
  }
}
