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
  Matrix();
  ~Matrix();
  static Matrix *gInstance;
  static Sprite *spriteInstance;

public:
  std::array<MatrixRow, MATRIX_ROWS> minos;
  static Matrix *getInstance();
  void deleteMino(int x, int y);
  MatrixRow getRow(int row);
  bool insertMino(Mino *);
  tryMoveResult *tryMove(Mino *, int x, int y);
  void move(Mino *, int x, int y);
  void createTexture();
  void printMatrix();
  void setRenderer(SDL_Renderer *);
};
