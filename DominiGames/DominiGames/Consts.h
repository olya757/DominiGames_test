#pragma once
#include "hge.h"
#include <hgecolor.h>
#include "HelpStructures.h"

const State USER_COLOR = State::White;
const State COMPUTER_COLOR = State::Black;
const unsigned int BOARD_WIDTH = 8;
const unsigned int BOARD_HEIGHT = 8;
const unsigned int SQRT_AMOUNT_OF_FIGURES = 3;
const double BOARD_CELL_WIDTH_PIXEL = 50;
const double BOARD_CELL_HEIGHT_PIXEL = 50;
const hgeColor GRAY_COLOR = {0.3,0.3,0.3,1};
const hgeColor WHITE_COLOR = { 0.8,0.8,0.8,1 };
const hgeColor BORDER_COLOR = { 0,0,0,1 };
const hgeColor PAWN_COLOR_WHITE = { 1,1,1,1 };
const hgeColor PAWN_COLOR_BLACK = { 0,0,0,1 };