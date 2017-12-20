#pragma once
#include "../sprite/Mino.h"
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
class Matrix {
private:
  std::array<MatrixRow, MATRIX_ROWS> minos;
  Matrix();
  ~Matrix();
  static Matrix *gInstance;

public:
  static Matrix *getInstance();
  MatrixRow getRow(int row);
  bool insertMino(Mino *);
  bool tryMove(Tetromino *, int x, int y);
  tryMoveResult *tryMove(Mino *, int x, int y);
  void move(Tetromino *, int x, int y);
  void move(Mino *, int x, int y);
};
