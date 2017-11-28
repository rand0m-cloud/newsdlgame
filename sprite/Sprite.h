#pragma once
#include "../color.h"
#include "../logging.h"
#include <SDL2/SDL.h>
class Sprite {
public:
  Sprite(SDL_Renderer *);
  ~Sprite();
  virtual void render(int milli, SDL_Texture *targetTexture);
  SDL_Rect sourceRect = {0, 0, 100, 100};
  virtual void createTexture();
  SDL_Rect dstRect = {0, 0, 100, 100};
  int *x, *y, *w, *h;

protected:
  SDL_Renderer *gRender = NULL;
  SDL_Texture *gTexture = NULL;
};

