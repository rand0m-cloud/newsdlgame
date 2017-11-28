#include "color.h"
#include "logging.h"
#include "sprite/ImageSprite.h"
#include "sprite/Mino.h"
#include "sprite/Sprite.h"
#include "sprite/Tetromino.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <vector>

#define TITLE "NewSDLGame"
#define WIDTH 400
#define HEIGHT 400
#define FPS 60
#define TPF (double)(1000 / FPS)

SDL_Window *gWindow = NULL;
SDL_Renderer *gRenderer = NULL;
bool gameRunning = true;
std::vector<Sprite *> sprites;
Uint32 currentTime = 0;
Uint32 lastTime = 0;

int init();
int graceful_exit();
void render();

int main(int argc, char const *argv[]) {
  if (init() != 0) {
    ERROR("init failed");
    return -1;
  }
  DEBUG("Init'd");
  Tetromino *box = new Tetromino(gRenderer, Tetromino::Shape::S);
  sprites.push_back(box);
  currentTime = lastTime = SDL_GetTicks();
  while (gameRunning) {
    lastTime = currentTime;
    if (SDL_GetTicks() - lastTime < TPF) {
      SDL_Delay(TPF - (SDL_GetTicks() - lastTime));
    }
    currentTime = SDL_GetTicks();

    SDL_Event *evt = new SDL_Event;
    while (SDL_PollEvent(evt)) {
      switch (evt->type) {
      case SDL_QUIT:
        gameRunning = false;
        break;
      }
    }
    render();
  }

  return graceful_exit();
}
int init() {
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
    ERROR("SDL_Init failed");
    return -1;
  }
  DEBUG("SDL init'd");
  gWindow = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_UNDEFINED,
                             SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, 0);
  if (gWindow == NULL) {
    ERROR("gWindow is null");
    return -1;
  }
  DEBUG("Window made");

  gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
  if (gRenderer == NULL) {
    ERROR("gRenderer is null");
  }

  return 0;
}
int graceful_exit() {
  SDL_Quit();
  return 0;
}

void render() {
  SDL_SetRenderTarget(gRenderer, NULL);
  SDL_SetRenderDrawColor(gRenderer, BACKGROUND.r, BACKGROUND.g, BACKGROUND.b,
                         BACKGROUND.a);
  SDL_RenderClear(gRenderer);

  for (Sprite *s : sprites) {
    // NULL targetTexture to target the screen
    s->render(currentTime - lastTime, NULL);
  }
  SDL_RenderPresent(gRenderer);
}
