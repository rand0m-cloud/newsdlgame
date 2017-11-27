#pragma once
#include "../color.h"
#include "../logging.h"
#include <SDL2/SDL.h>
class Sprite {
public:
  Sprite(SDL_Renderer *);
  ~Sprite();
  virtual SDL_Texture *render();
  SDL_Rect sourceRect = {0, 0, 100, 100};
  virtual void createTexture();
  SDL_Rect dstRect = {0, 0, 100, 100};
protected:
  SDL_Renderer *gRender;
  SDL_Texture *gTexture;
  int *x, *y, *w, *h;
};
