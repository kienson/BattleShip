#include "board.h"

// Function to initialize a board
Board* initializeBoard(int size) {
    Board *newBoard = malloc(sizeof(Board)); // Allows memory for the board
    if (newBoard == NULL) {
        // Managing memory allocation failure
        fprintf(stderr, "Board memory allocation error\n");
        return NULL;
    }

    newBoard->size = size; // Sets board size
    // Allocates memory for board cells
    newBoard->cells = malloc(size * sizeof(CellsType*));
    if (newBoard->cells == NULL) {
        // Managing memory allocation failure
        free(newBoard);
        fprintf(stderr, "Memory allocation error for board cells\n");
        return NULL;
    }

    // Initializes every cells on the board to WATER
    for (int i = 0; i < size; i++) {
        newBoard->cells[i] = malloc(size * sizeof(CellsType));
        if (newBoard->cells[i] == NULL) {
            // Managing memory allocation failure
            for (int j = 0; j < i; j++) {
                free(newBoard->cells[j]); // Free memory allocated up to now
            }
            free(newBoard->cells);
            free(newBoard);
            fprintf(stderr, "Memory allocation error for board lines\n");
            return NULL;
        }

        for (int j = 0; j < size; j++) {
            newBoard->cells[i][j] = WATER; // Initialize the cell for WATER
        }
    }

    return newBoard; // Returns a pointer to the initialized board
}

// Function to display the board
void displayBoard(Board *board) {
    printf("  "); // Space for column number alignment
    for (int i = 0; i < board->size; i++) {
        printf("%d ", i); // Display column numbers
    }
    printf("\n");

    for (int y = 0; y < board->size; y++) {
        printf("%d ", y); // Display line numbers
        for (int x = 0; x < board->size; x++) {
            // Select the character to be displayed according to the state of the box
            char displayCell;
            switch (board->cells[y][x]) {
                case WATER:
                    displayCell = '~'; // Watter 
                    break;
                case WATER_SHOT:
                    displayCell = 'o'; // Missed shot
                    break;
                case BOAT:
                    displayCell = 'B'; // Boat (untouched)
                    break;
                case WRECK:
                    displayCell = 'x'; // Boat touched / poured
                    break;
                default:
                    displayCell = '?'; // State unknown
            }
            printf("%c ", displayCell);
        }
        printf("\n");
    }
}


//Function that displays the opponent's board without revealing its ships
void displayBoardOpponent(Board *board) {
    printf("  "); // Space for column number alignment
    for (int i = 0; i < board->size; i++) {
        printf("%d ", i); // Display column numbers
    }
    printf("\n");

    for (int y = 0; y < board->size; y++) {
        printf("%d ", y); // Display line numbers
        for (int x = 0; x < board->size; x++) {
            char displayedCell;
            switch (board->cells[y][x]) {
                case WATER_SHOT:
                    displayedCell = 'o'; // Missed shot
                    break;
                case WRECK:
                    displayedCell = 'X'; // Boat hit
                    break;
                default:
                    displayedCell = '~'; // Water or boat not revealed
            }
            printf("%c ", displayedCell);
        }
        printf("\n");
    }
}