#pragma once
#include "Mino.h"
#include <SDL2/SDL.h>
typedef SDL_Point TetrominoPattern[4];
#define pos(x, y)                                                              \
  { x, y }
/*
  [*][*]
  [*][*]
*/
const TetrominoPattern O_SHAPE = {pos(0, 0), pos(1, 0), pos(0, 1), pos(1, 1)};
/*
  [*]
  [*]
  [*]
  [*]
*/
const TetrominoPattern I_SHAPE = {pos(0, 0), pos(0, 1), pos(0, 2), pos(0, 3)};
/*
  [ ][*][ ]
  [*][*][*]
*/
const TetrominoPattern T_SHAPE = {pos(1, 0), pos(0, 1), pos(1, 1), pos(2, 1)};
/*
  [*]
  [*]
  [*][*]
*/
const TetrominoPattern L_SHAPE = {pos(0, 0), pos(0, 1), pos(0, 2), pos(1, 2)};
/*
  [ ][*]
  [ ][*]
  [*][*]

*/
const TetrominoPattern J_SHAPE = {pos(1, 0), pos(1, 1), pos(1, 2), pos(0, 2)};
/*
 [ ][*][*]
 [*][*][ ]
*/

const TetrominoPattern S_SHAPE = {pos(0, 1), pos(1, 1), pos(1, 0), pos(2, 0)};
/*
  [*][*][ ]
  [ ][*][*]
*/
const TetrominoPattern Z_SHAPE = {pos(0, 0), pos(1, 0), pos(1, 1), pos(2, 1)};

#undef pos