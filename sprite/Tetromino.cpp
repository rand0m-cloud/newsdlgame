#include "Tetromino.h"
#include "Mino.h"
#include <SDL2/SDL.h>

Tetromino::Tetromino(SDL_Renderer *mRenderer, enum Tetromino::Shape type)
    : gType(type) {
  Mino::Color color;
  switch (gType) {
  case O:
    color = Mino::Color::yellow;
    break;
  case I:
    color = Mino::Color::lightblue;
    break;
  case T:
    color = Mino::Color::purple;
    break;
  case L:
    color = Mino::Color::orange;
    break;
  case J:
    color = Mino::Color::darkblue;
    break;
  case S:
    color = Mino::Color::green;
    break;
  case Z:
    color = Mino::Color::red;
    break;
  default:
    ERROR("Switch defaulted");
    break;
  }
  for (int i = 0; i < 4; i++) {
    Mino *m = new Mino(mRenderer, color);
    minos.push_back(m);
  }
}
Tetromino::~Tetromino() {}
