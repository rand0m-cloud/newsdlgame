#pragma once
#include "Mino.h"
#include <SDL2/SDL.h>
typedef SDL_Rect TetrominoPattern[4];
#define sideLength MINO_SIZE
#define pos(x, y)                                                              \
  { x, y, sideLength, sideLength }
/*
  [*][*]
  [*][*]
*/
const TetrominoPattern O_SHAPE = {pos(0, 0), pos(sideLength, 0),
                                  pos(0, sideLength),
                                  pos(sideLength, sideLength)};
/*
  [*]
  [*]
  [*]
  [*]
*/
const TetrominoPattern I_SHAPE = {pos(0, 0), pos(0, sideLength),
                                  pos(0, 2 * sideLength),
                                  pos(0, 3 * sideLength)};
/*
  [ ][*][ ]
  [*][*][*]
*/
const TetrominoPattern T_SHAPE = {pos(sideLength, 0), pos(0, sideLength),
                                  pos(sideLength, sideLength),
                                  pos(2 * sideLength, sideLength)};
/*
  [*]
  [*]
  [*][*]
*/
const TetrominoPattern L_SHAPE = {pos(0, 0), pos(0, sideLength),
                                  pos(0, 2 * sideLength),
                                  pos(sideLength, 2 * sideLength)};
/*
  [ ][*]
  [ ][*]
  [*][*]

*/
const TetrominoPattern J_SHAPE = {
    pos(sideLength, 0), pos(sideLength, sideLength),
    pos(sideLength, 2 * sideLength), pos(0, 2 * sideLength)};
/*
 [ ][*][*]
 [*][*][ ]
*/

const TetrominoPattern S_SHAPE = {pos(0, sideLength),
                                  pos(sideLength, sideLength),
                                  pos(sideLength, 0), pos(2 * sideLength, 0)};
/*
  [*][*][ ]
  [ ][*][*]
*/
const TetrominoPattern Z_SHAPE = {pos(0, 0), pos(sideLength, 0),
                                  pos(sideLength, sideLength),
                                  pos(2 * sideLength, sideLength)};

#undef sideLength
#undef pos