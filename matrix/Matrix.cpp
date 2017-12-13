#include "Matrix.h"
#include "../sprite/Mino.h"
#include "../sprite/Tetromino.h"
#include <SDL2/SDL.h>
#include <algorithm>
Matrix *Matrix::gInstance = NULL;
Matrix::Matrix() {
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
bool Matrix::tryMove(Tetromino *mTetro, int x, int y) {
  bool canMove = true;
  for (Mino *m : mTetro->minos) {
    tryMoveResult *result = tryMove(m, x, y);
    if (result->canMove) {
      continue;
    } else if (result->isBlocked) {
      bool inTetro = std::find(mTetro->minos.begin(), mTetro->minos.end(),
                               result->blockingMino) != mTetro->minos.end();
      if (inTetro) {
        continue;
      }
    }
    canMove = false;
  }
  return canMove;
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
void Matrix::move(Tetromino *mTetro, int x, int y) {
  for (Mino *m : mTetro->minos) {
    move(m, x, y);
  }
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
  minos[oldy][oldx] = NULL;
  minos[newy][newx] = mMino;
  mMino->gLocation.x = newx;
  mMino->gLocation.y = newy;
  DEBUG("Moved mino [" << oldy << "," << oldx << "] to [" << newy << "," << newx
                       << "]");
}