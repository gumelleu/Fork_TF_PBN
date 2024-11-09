// graphics.h
#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdbool.h>
#include "board.h"

bool graphics_init();
void graphics_draw_board();
void graphics_cleanup();

#endif