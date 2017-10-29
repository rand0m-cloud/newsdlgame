#include "Logging.h"
#include <SDL2/SDL.h>
#include <iostream>

#define TITLE "NewSDLGame"
#define WIDTH 400
#define HEIGHT 400

SDL_Window *gWindow = NULL;
SDL_Renderer *gRenderer = NULL;

int init();
int graceful_exit();

int main(int argc, char const *argv[]) {
  std::cout << "Test" << std::endl;
  if (init() != 0) {
    ERROR("init failed");
  }
  DEBUG("Init'd");
  graceful_exit();

  return 0;
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
    ERROR("")
  }

  return 0;
}
int graceful_exit() {
  SDL_Quit();
  return 0;
}
