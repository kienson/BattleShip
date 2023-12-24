#ifndef BOARD_H
#define BOARD_H

#include "boat.h"
#include "game.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to initialize a board
Board* initializeBoard(int size);

// Function to randomly place a boat on the board
bool placeBoat(Board *board, Boat *boat);

// Function to display the board
void displayBoard(Board *board);

// Function that frees up play space
void freeBoard(Board *board);

#endif