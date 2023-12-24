Battleship Game in C
Overview :

This program is a C implementation of the classic game Battleship. It features a player 	versus computer gameplay, where the player attempts to sink the computer's fleet of ships before the computer sinks theirs.

How to Compile and Run :

	Compile the code using a C compiler:	- make lib			(static library)
						- make BattleShipDelMondo
	Run the compiled program: ./BattleShipDelMondo

Game Features :

	Initialization: The game initializes two game boards, one for the player and one for the computer.
	Ship Placement: Ships are placed randomly on both the player's and the computer's boards.
	Game Loop: The game alternates between the player's turn and the computer's turn.
	Player's Turn: The player inputs coordinates to attack on the computer's board.
	Computer's Turn: The computer randomly selects coordinates to attack on the player's board.
	End Game: The game ends when all the ships of either the player or the computer are sunk.

Functions (computer = opponent) :

	createboat: Creates a ship with specified size and orientation.
	initializeBoard: Initializes the game board with specified size.
	placeBoat: Places a ship on the game board.
	boatAlive: Checks if a ship is still afloat.
	displayBoard: Displays the game board.
	Playerturn: Manages the player's turn.
	Opponentturn: Manages the computer's turn.
	createGame: Create two boards, one for the player and one for the computer, and then place the ships randomly for both sides.
	allBoatSunk: Checks if all ships are sunk.
	freeGame: Frees allocated memory at the end of the game.

Gameplay :

	The game starts by initializing the boards and placing the ships.
	Players take turns to attack each other's ships by specifying coordinates.
	The game displays the result of each attack.
	The game ends when all the ships of one player are sunk.
