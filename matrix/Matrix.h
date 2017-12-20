#pragma once
#include "../sprite/Mino.h"
#include "../sprite/Sprite.h"
#include "../sprite/Tetromino.h"
#include <array>

#define MATRIX_ROWS 40
#define MATRIX_COLUMNS 10
struct tryMoveResult {
  bool canMove;
  bool isBlocked;
  Mino *blockingMino;
};
typedef std::array<Mino *, MATRIX_COLUMNS> MatrixRow;
class Matrix : public Sprite {
private:
  std::array<MatrixRow, MATRIX_ROWS> minos;
  Matrix();
  ~Matrix();
  static Matrix *gInstance;
  static Sprite *spriteInstance;

public:
  static Matrix *getInstance();

  MatrixRow getRow(int row);
  bool insertMino(Mino *);
  tryMoveResult *tryMove(Mino *, int x, int y);
  void move(Mino *, int x, int y);
  void createTexture();
  void setRenderer(SDL_Renderer *);
};
