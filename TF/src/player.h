// player.h
#ifndef PLAYER_H
#define PLAYER_H

#include "types.h" // Inclui types.h para reconhecer 'Piece'

typedef struct {
    Piece color;
} Player;

void player_init(Player *player1, Player *player2);
Player* player_next_turn(Player *currentPlayer);

#endif