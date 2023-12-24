#include "boat.h"

// Function to create a boat
Boat* createboat(int size, int x, int y, char orientation) {
    Boat *newBoat = malloc(sizeof(Boat));  // Allocating memory for a new boat
    if (newBoat == NULL) {
        // Managing memory allocation failure
        fprintf(stderr, "Memory allocation error for boat\n");
        return NULL;
    }

    // Initializing boat attributes
    newBoat->size = size;
    newBoat->x = x;
    newBoat->y = y;
    newBoat->orientation = orientation;

    return newBoat; // Returns a pointer to the new boat
}

// Function to randomly place a boat on the board
bool placeBoat(Board *board, Boat *boat) {
    bool Validplacement;
    int attempt = 0;
    const int MAX_ATTEMPT = 100;

    srand(time(NULL)); // Initializing the random number generator

    do {
        Validplacement = true;
        // Choose a random orientation
        boat->orientation = (rand() % 2 == 0) ? 'H' : 'V'; // H = horizontal V = vertical

        // Choose a random position, respecting the size of the board and the boat
        if (boat->orientation == 'H') {
            boat->x = rand() % (board->size - boat->size + 1);
            boat->y = rand() % board->size;
        } else { // vertical orientation
            boat->x = rand() % board->size;
            boat->y = rand() % (board->size - boat->size + 1);
        }

        // Check if the boat overlaps another boat or exceeds the limits
        for (int i = 0; i < boat->size; i++) {
            int x = boat->x + (boat->orientation == 'H' ? i : 0);
            int y = boat->y + (boat->orientation == 'V' ? i : 0);

            if (board->cells[y][x] != WATER) {
                Validplacement = false;
                break;
            }
        }

        attempt++;

    } while (!Validplacement && attempt < MAX_ATTEMPT);

    // If a valid location is found, place the boat
    if (Validplacement) {
        for (int i = 0; i < boat->size; i++) {
            int x = boat->x + (boat->orientation == 'H' ? i : 0);
            int y = boat->y + (boat->orientation == 'V' ? i : 0);

            board->cells[y][x] = BOAT;
        }
        return true;
    }

    return false; // Returns false if no valid placement found
}

// Function to check if a boat is still alive
bool boatAlive(Boat *boat, Board *board) {
    for (int i = 0; i < boat->size; i++) {
        int x = boat->x + (boat->orientation == 'H' ? i : 0);
        int y = boat->y + (boat->orientation == 'V' ? i : 0);

        if (board->cells[y][x] != WRECK) {
            // If at least one of the boat's cells is not a WRECK, the boat is still alive.
            return true;
        }
    }

    // All the cells on the boat are WRECKs, so the boat is sunk.
    return false;
}

//Function that checks whether all boats have sunk or not
bool allBoatSunk(Boat **boat, Board *board) {
    for (int i = 0; i < BOAT_NUMBER; i++) {
        if (boatAlive(boat[i], board)) {
            return false; // At least one boat is still alive
        }
    }
    return true; // All boats are sunk
}