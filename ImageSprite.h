#include <SDL2/SDL.h>
#include "Sprite.h"
class ImageSprite : Sprite{
    public:
        ImageSprite(SDL_Renderer*);
        ~ImageSprite();
}