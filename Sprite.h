#include <SDL2/SDL.h>
class Sprite{
    private:
    public:
        Sprite(SDL_Renderer*);
        ~Sprite();
        SDL_Texture* render();
        SDL_Rect rect;
}