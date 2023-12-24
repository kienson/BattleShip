#ifndef GAME_H
#define GAME_H

#include "boat.h"
#include "board.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function that creates the game with the 2 boards
Game* createGame();

// Function that checks whether all boats have sunk or not
bool allBoatSunk(Boat **boat, Board *board);

// Function that frees up play space
void freeGame(Game *game);

// Function that displays the opponent's board without revealing its ships
void displayBoardOpponent(Board *board);

// Game turn function (player)
void Playerturn(Board *boardOpponent);

// Game turn function (opponent)
void Opponentturn(Board *boardPlayer);

#endif