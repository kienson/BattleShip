#include "game.h"

// Game turn function (player)
void Playerturn(Board *boardOpponent) {
    int x, y;
    printf("Your turn. Enter firing coordinates (x y):");
    scanf("%d %d", &x, &y);

    // Check that contact details are valid
    if (x >= 0 && x < boardOpponent->size && y >= 0 && y < boardOpponent->size) {
        if (boardOpponent->cells[y][x] == BOAT) {
            printf("Touched!\n");
            boardOpponent->cells[y][x] = WRECK;
        } else if (boardOpponent->cells[y][x] == WATER) {
            printf("Missed!\n");
            boardOpponent->cells[y][x] = WATER_SHOT;
        }
    } else {
        printf("Invalid coordinates. Please try again.\n");
    }
}

// Game turn function (opponent)
void Opponentturn(Board *boardPlayer) {
    srand(time(NULL)); // Initialize the random number generator
    int x, y;

    do {
        x = rand() % boardPlayer->size;
        y = rand() % boardPlayer->size;
    } while (boardPlayer->cells[y][x] == WATER_SHOT || boardPlayer->cells[y][x] == WRECK); // Avoid firing at the same cell

    if (boardPlayer->cells[y][x] == BOAT) {
        printf("The computer hit a boat on %d, %d!\n", x, y);
        boardPlayer->cells[y][x] = WRECK;
    } else {
        printf("The computer was missing on %d, %d.\n", x, y);
        boardPlayer->cells[y][x] = WATER_SHOT;
    }
}

//Function that creates the game with the 2 boards
Game* createGame() {
    Game *newGame = malloc(sizeof(Game));
    if (newGame == NULL) {
        fprintf(stderr, "Memory allocation error for game\n");
        return NULL;
    }

    // Initialize boards for player and opponent
    newGame->boardPlayer = initializeBoard(BOARD_SIZE);
    newGame->boardOpponent = initializeBoard(BOARD_SIZE);

    if (newGame->boardPlayer == NULL || newGame->boardOpponent == NULL) {
        fprintf(stderr, "Board initialization error\n");
        free(newGame->boardPlayer);
        free(newGame->boardOpponent);
        free(newGame);
        return NULL;
    }

    srand(time(NULL)); // Initializing the random number generator

    // Place boats randomly on each board
    for (int i = 0; i < BOAT_NUMBER; i++) {
        // Create and place boats for the player
        Boat *boatPlayer;
        do {
            int size = rand() % (BOAT_MAX_SIZE - BOAT_MIN_SIZE + 1) + BOAT_MIN_SIZE;
            int x = rand() % BOARD_SIZE;
            int y = rand() % BOARD_SIZE;
            char orientation = (rand() % 2 == 0) ? 'H' : 'V';
            boatPlayer = createboat(size, x, y, orientation);
        } while (boatPlayer == NULL || !placeBoat(newGame->boardPlayer, boatPlayer));
        newGame->boatPlayer[i] = boatPlayer;

        // Creating and placing boats for the computer
        Boat *boatOpponent;
        do {
            int size = rand() % (BOAT_MAX_SIZE - BOAT_MIN_SIZE + 1) + BOAT_MIN_SIZE;
            int x = rand() % BOARD_SIZE;
            int y = rand() % BOARD_SIZE;
            char orientation = (rand() % 2 == 0) ? 'H' : 'V';
            boatOpponent = createboat(size, x, y, orientation);
        } while (boatOpponent == NULL || !placeBoat(newGame->boardOpponent, boatOpponent));
        newGame->boatOpponent[i] = boatOpponent;
    }

    return newGame; // Return initialized set
}

//Function that frees up play space
void freeGame(Game *game) {
    if (game != NULL) {
        // Free the boards
        if (game->boardPlayer != NULL) {
            for (int i = 0; i < BOARD_SIZE; i++) {
                free(game->boardPlayer->cells[i]);
            }
            free(game->boardPlayer->cells);
            free(game->boardPlayer);
        }

        if (game->boardOpponent != NULL) {
            for (int i = 0; i < BOARD_SIZE; i++) {
                free(game->boardOpponent->cells[i]);
            }
            free(game->boardOpponent->cells);
            free(game->boardOpponent);
        }

        // Freeing the boats
        for (int i = 0; i < BOAT_NUMBER; i++) {
            free(game->boatPlayer[i]);
            free(game->boatOpponent[i]);
        }

        // Finally, free up the play structure itself
        free(game);
    }
}