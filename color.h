#pragma once
#include <SDL2/SDL.h>
struct color {
  Uint8 r;
  Uint8 g;
  Uint8 b;
  Uint8 a;
};
const color BLACK = {0, 0, 0, 255};
const color WHITE = {255, 255, 255, 255};
const color RED = {255, 0, 0, 255};
