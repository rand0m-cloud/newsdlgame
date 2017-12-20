#include "Tetromino.h"
#include "../matrix/Matrix.h"
#include <algorithm>
Tetromino::Tetromino(SDL_Renderer *mRenderer, enum Tetromino::Shape type,
                     int startX, int startY)
    : gType(type) {
  Mino::Color color;
  switch (gType) {
  case O:
    color = Mino::Color::yellow;
    gPattern = &O_SHAPE;
    break;
  case I:
    color = Mino::Color::lightblue;
    gPattern = &I_SHAPE;
    break;
  case T:
    color = Mino::Color::purple;
    gPattern = &T_SHAPE;
    break;
  case L:
    color = Mino::Color::orange;
    gPattern = &L_SHAPE;
    break;
  case J:
    color = Mino::Color::darkblue;
    gPattern = &J_SHAPE;
    break;
  case S:
    color = Mino::Color::green;
    gPattern = &S_SHAPE;
    break;
  case Z:
    color = Mino::Color::red;
    gPattern = &Z_SHAPE;
    break;
  default:
    ERROR("Switch defaulted");
    break;
  }
  for (int i = 0; i < 4; i++) {
    Mino *m = new Mino(mRenderer, color);
    SDL_Point const *shape = &(*gPattern)[i];

    minos.push_back(m);
    m->gLocation = {startX + shape->x, startY + shape->y};
    if (Matrix::getInstance()->insertMino(m) == false) {
      DEBUG("Can not insert Mino");
    }
  }
}
Tetromino::~Tetromino() { DEBUG("Tetromino Deleted"); }

void Tetromino::frame() {
  if (isActive) {
    int dx = 0;
    int dy = 0;
    Uint8 const *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_W])
      dy = -1;
    if (state[SDL_SCANCODE_S])
      dy = 1;
    if (state[SDL_SCANCODE_A])
      dx = -1;
    if (state[SDL_SCANCODE_D])
      dx = 1;
    if (state[SDL_SCANCODE_Q])
      rotate(Tetromino::Rotation::CCW);
    if (state[SDL_SCANCODE_E])
      rotate(Tetromino::Rotation::CW);
    if (dx != 0 || dy != 0) {
      if (tryMove(dx, dy))
        move(dx, dy);
    }
  }
}
bool Tetromino::moveDown() {
  if (tryMove(0, 1) == false) {
    return false;
  }
  move(0, 1);
  return true;
}
void printVector(std::vector<std::vector<Mino *>> v) {
  for (std::vector<Mino *> row : v) {
    for (Mino *m : row) {
      std::cout << m << ",";
    }
    std::cout << std::endl;
  }
}
bool Tetromino::rotate(enum Tetromino::Rotation direction) {
  struct boundingBox {
    int left = -1;
    int right = -1;
    int top = -1;
    int bottom = -1;
    int width = -1;
    int height = -1;
  } box;
  for (Mino *m : minos) {
    SDL_Point mLocation = m->gLocation;
    if (box.left == -1 || mLocation.x < box.left) {
      box.left = mLocation.x;
    }
    if (box.right == -1 || mLocation.x > box.right) {
      box.right = mLocation.x;
    }
    if (box.top == -1 || mLocation.y < box.top) {
      box.top = mLocation.y;
    }
    if (box.bottom == -1 || mLocation.y > box.bottom) {
      box.bottom = mLocation.y;
    }
  }
  box.width = box.right - box.left + 1;
  box.height = box.bottom - box.top + 1;
  if (box.width != box.height) {
    if (box.width < box.height) {
      box.width = box.height;
    } else {
      box.height = box.width;
    }
  }
  // [y][x]
  std::vector<std::vector<Mino *>> boxToRotate(
      box.height, std::vector<Mino *>(box.width, NULL));
  // std::fill(boxToRotate.begin(), boxToRotate.end(), NULL);
  for (Mino *m : minos) {
    SDL_Point mLocation = m->gLocation;
    boxToRotate[mLocation.y - box.top][mLocation.x - box.left] = m;
  }
  DEBUG("[bb] left: " << box.left << ", right: " << box.right
                      << ", top: " << box.top << ", bottom:" << box.bottom
                      << ", width:" << box.width << ", height:" << box.height);
  printVector(boxToRotate);
  std::vector<std::vector<Mino *>> transposedBox(
      box.height, std::vector<Mino *>(box.width, NULL));
  DEBUG("Transposed:");
  for (unsigned int y = 0; y < transposedBox.size(); y++) {
    for (unsigned int x = 0; x < transposedBox[y].size(); x++) {
      transposedBox[y][x] = boxToRotate[x][y];
    }
  }
  // printVector(transposedBox);
  std::vector<std::vector<Mino *>> finalBox(
      box.height, std::vector<Mino *>(box.width, NULL));
  if (direction == Tetromino::Rotation::CW) {
    for (unsigned int row = 0; row < finalBox.size(); row++) {
      finalBox[row] = transposedBox[row];
      std::reverse(finalBox[row].begin(), finalBox[row].end());
    }
    DEBUG("CW");
  } else {
    for (unsigned int y = 0; y < finalBox.size(); y++) {
      for (unsigned int x = 0; x < finalBox[y].size(); x++) {
        finalBox[y][x] = transposedBox[transposedBox.size() - 1 - y][x];
      }
    }
    DEBUG("CCW");
  }
  printVector(finalBox);
  for (unsigned int y = 0; y < finalBox.size(); y++) {
    for (unsigned int x = 0; x < finalBox[y].size(); x++) {
      if (finalBox[y][x] != NULL) {
        // Matrix::getInstance()->tryMove(Mino *, int x, int y)
      }
    }
  }
  return true;
}
bool interpretResult(tryMoveResult *result, std::vector<Mino *> minos) {
  if (result->canMove) {
    return true;
  } else if (result->isBlocked) {
    bool inTetro = std::find(minos.begin(), minos.end(),
                             result->blockingMino) != minos.end();
    if (inTetro) {
      return true;
    }
  }
  return false;
}
bool Tetromino::tryMove(int x, int y) {
  bool canMove = true;
  for (Mino *m : minos) {
    tryMoveResult *result = Matrix::getInstance()->tryMove(m, x, y);
    if (!interpretResult(result, minos))
      canMove = false;
  }
  return canMove;
}

void Tetromino::move(int x, int y) {

  for (Mino *m : minos) {
    Matrix::getInstance()->move(m, x, y);
  }
}
