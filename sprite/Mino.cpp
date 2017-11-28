#include "Mino.h"
#include <SDL2/SDL.h>
Mino::Mino(SDL_Renderer *mRenderer, enum Color mColor)
    : ImageSprite(mRenderer), gColor(mColor) {
  std::string file = "images/";
  switch (gColor) {
  case cyan:
    file += "cyan.png";
    break;
  case yellow:
    file += "yellow.png";
    break;
  case purple:
    file += "purple.png";
    break;
  case green:
    file += "green.png";
    break;
  case red:
    file += "red.png";
    break;
  case lightblue:
    file += "lightblue.png";
    break;
  case darkblue:
    file += "darkblue.png";
    break;
  case orange:
    file += "orange.png";
    break;
  default:
    ERROR("MinoColor is invalid");
  }
  changeImage(file);
  *w = 25;
  *h = *w;
}
Mino::~Mino() {}