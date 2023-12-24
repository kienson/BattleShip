#ifndef BOAT_H
#define BOAT_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/// Case types
typedef enum {
    WATER,
    WATER_SHOT,
    BOAT,
    WRECK
} CellsType;

// Constants
#define BOAT_NUMBER 5
#define BOARD_SIZE 10
#define BOAT_MAX_SIZE 3
#define BOAT_MIN_SIZE 1

// Structure for a boat
typedef struct {
    int size;
    int x, y; // Reference position
    char orientation; // H' for horizontal, 'V' for vertical
} Boat;

// Board structure
typedef struct {
    CellsType **cells;
    int size;
} Board;

// Play structure
typedef struct {
    Board *boardPlayer, *boardOpponent;
    Boat *boatPlayer[BOAT_NUMBER];
    Boat *boatOpponent[BOAT_NUMBER];
} Game;

// Function to create a boat
Boat* createboat(int size, int x, int y, char orientation);

// Function to check if a boat is still alive
bool boatAlive(Boat *boat, Board *board);

#endif