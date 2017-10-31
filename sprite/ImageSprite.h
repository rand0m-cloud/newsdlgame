#include "Sprite.h"
#include <SDL2/SDL.h>
class ImageSprite : Sprite {
public:
  ImageSprite(SDL_Renderer *);
  ~ImageSprite();
}