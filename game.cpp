#include "color.h"
#include "logging.h"
#include "matrix/Matrix.h"
#include "sprite/ImageSprite.h"
#include "sprite/Mino.h"
#include "sprite/Sprite.h"
#include "sprite/Tetromino.h"
#include <SDL2/SDL.h>
#include <algorithm>
#include <iostream>
#include <vector>

#define TITLE "NewSDLGame"
#define WIDTH MATRIX_COLUMNS *MINO_SIZE
#define HEIGHT MATRIX_ROWS *MINO_SIZE
#define DEFAULT_FPS 60
#define TPF(x) (double)(1000 / x)

int fps = DEFAULT_FPS;
SDL_Window *gWindow = NULL;
SDL_Renderer *gRenderer = NULL;
bool gameRunning = true;
Uint32 currentTime = 0;
Uint32 lastTime = 0;
Tetromino *activePiece = NULL;

int init();
int graceful_exit();
void render();
void addTetromino();

int main(int argc, char const *argv[]) {
  if (init() != 0) {
    ERROR("init failed");
    return -1;
  }
  DEBUG("Init'd");

  addTetromino();
  currentTime = lastTime = SDL_GetTicks();
  while (gameRunning) {
    lastTime = currentTime;
    if (SDL_GetTicks() - lastTime < TPF(fps)) {
      SDL_Delay(TPF(fps) - (SDL_GetTicks() - lastTime));
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
    if (activePiece->moveDown() == false) {
      addTetromino();
    }
    render();
  }

  return graceful_exit();
}
int init() {
  srand(time(NULL));
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
  char *fps_env = SDL_getenv("FPS");
  if (fps_env) {
    fps = atoi(fps_env);
  }
  Matrix::getInstance()->setRenderer(gRenderer);
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
  // NULL targetTexture to target the screen
  if (activePiece)
    activePiece->frame();
  Matrix::getInstance()->render(currentTime - lastTime, NULL);
  SDL_RenderPresent(gRenderer);
}
void addTetromino() {
  Tetromino::Shape shape = static_cast<Tetromino::Shape>(rand() % 7);
  Tetromino *mTetro = new Tetromino(gRenderer, shape, 5, 5);
  mTetro->isActive = true;
  if (activePiece != NULL) {
    delete activePiece;
  }
  activePiece = mTetro;
}
