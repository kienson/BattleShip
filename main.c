#include "game.h"

//Main function for playing the game
int main() {
    // Game initialization
    Game *game = createGame();
    if (game == NULL) {
        fprintf(stderr, "Error during game initialization.\n");
        return 1;
    }

    bool endGame = false;
    bool isPlayersturn = true; // Assuming the player starts

    // Play loop
    while (!endGame) {
        if (isPlayersturn) {
            printf("Player's turn :\n");
            printf("your board :\n");
            displayBoard(game->boardPlayer);
            printf("Opponent board :\n");
            displayBoardOpponent(game->boardOpponent);
            Playerturn(game->boardOpponent);
        } else {
            printf("Computer tower :\n");
            Opponentturn(game->boardPlayer);
        }

        // Check the state of the game to determine if it's the end
        if (allBoatSunk(game->boatOpponent, game->boardOpponent)) {
            printf("Congratulations! You've won! EZ!!!\n");
            endGame = true;
        } else if (allBoatSunk(game->boatPlayer, game->boardPlayer)) {
            printf("The opponent has won. Try again!\n");
            endGame = true;
        }

        isPlayersturn = !isPlayersturn; // Changing players for the next round
    }

    // Clearing and freeing the memory (it has to be freed here because I didn't do it in the ds :) )
    freeGame(game);

    return 0;
}