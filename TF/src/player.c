// player.h
#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"
#include "types.h"

typedef struct {
    Piece color;
} Player;

void player_init(Player *player1, Player *player2);
Player* player_next_turn(Player *currentPlayer);

#endif