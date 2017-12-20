#include "Matrix.h"
#include <SDL2/SDL.h>
#include <algorithm>
Matrix *Matrix::gInstance = NULL;
Matrix::Matrix() : Sprite(NULL) {
  for (int y = 0; y < MATRIX_ROWS; y++) {
    for (int x = 0; x < MATRIX_COLUMNS; x++) {
      minos[y][x] = NULL;
    }
  }
}
Matrix::~Matrix() {}
Matrix *Matrix::getInstance() {
  if (gInstance == NULL)
    gInstance = new Matrix();
  return gInstance;
}
bool Matrix::insertMino(Mino *m) {
  int x = m->gLocation.x;
  int y = m->gLocation.y;
  if (m == NULL)
    DEBUG("Mino is null");
  if (x < 0 || x > MATRIX_COLUMNS - 1) {
    DEBUG("X is invalid" << x);
    return false;
  }
  if (y < 0 || y > MATRIX_ROWS - 1) {
    DEBUG("Y is invalid" << y);
    return false;
  }
  if (minos[y][x] == NULL) {
    minos[y][x] = m;
    return true;
  }
  return false;
}
tryMoveResult *Matrix::tryMove(Mino *mMino, int x, int y) {
  tryMoveResult *result = new tryMoveResult;
  result->blockingMino = NULL;
  result->canMove = false;
  result->isBlocked = false;
  int newx = mMino->gLocation.x + x;
  int newy = mMino->gLocation.y + y;
  if (newx < 0 || newx > MATRIX_COLUMNS - 1) {
    return result;
  }
  if (newy < 0 || newy > MATRIX_ROWS - 1) {
    return result;
  }
  if (minos[newy][newx] == NULL) {
    result->canMove = true;

  } else {
    result->isBlocked = true;
    result->blockingMino = minos[newy][newx];
  }
  return result;
}
void Matrix::move(Mino *mMino, int x, int y) {
  int oldx = mMino->gLocation.x;
  int oldy = mMino->gLocation.y;
  int newx = oldx + x;
  int newy = oldy + y;
  if (newx < 0 || newx > MATRIX_COLUMNS - 1) {
    DEBUG("X is invalid:" << x);
    return;
  }
  if (newy < 0 || newy > MATRIX_ROWS - 1) {
    DEBUG("Y is invalid:" << y);
    return;
  }
  if (minos[oldy][oldx] == mMino) {
    minos[oldy][oldx] = NULL;
  }
  minos[newy][newx] = mMino;
  mMino->gLocation.x = newx;
  mMino->gLocation.y = newy;
}
void Matrix::createTexture() {
  for (MatrixRow row : minos) {
    for (Mino *m : row) {
      if (m)
        m->render(0, gTexture);
    }
  }
}
void Matrix::setRenderer(SDL_Renderer *mRenderer) { gRender = mRenderer; }