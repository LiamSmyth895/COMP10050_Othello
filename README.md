# COMP10050_Othello
Liam Smyth's project for COMP10050 Assignment 2, a board game called Othello

In this project, each players' information is stored in a struct which contains their colour, score and name. The board is stored as a 2d array.
I chose to use a 2d array for the board so that I would have some way of linking nearby tiles to each other, a crucial part of deciding whether or not a move is valid.

The board is an integer array with each different type of tile haveing a different number associated with it.
The outside of the board consists of -1s, to indicate that it is out of bounds and to avoid overflow errors when we check those tiles
White tiles are 2s.
Black tiles are 1s.
Wmpty tiles are 0s.

To check if a move is valid, I needed to check its validity in all eight directions.
I decided to create a single function to check whether or not a move was valid.
This function contained 8 sepereate functions that would check the validity in each direction. I did this because the program needs to know in which direction(s) to change the color of the tiles, given that it is a valid move.

The game ends when one of two conditions is reached:
1. When the board is full. This is checked by adding up bothe players' scores and checking whether or not it is less than 64 (the total number of tiles on the board).
2. When neither player has a valid move. This is checked by using an integer variable called counter. Counter is incremented each time that a player has no valid move available to them but counter is reset to 0 every time a player makes a move. The game ends if counter reaches a value of 2, as this indicates that neither player has a valid move.

For the program to know which players' turn it is, a new player struct called currentPlayer is initialised and a variable called playerTurn is created which gets incremented at the end of each turn.
At the start of each turn, playerTurn is divided modulo 2. If the result is equal to 0, then it is player 1's turn and their info is copied into currentPlayer.
Else, it is player 2's turn and their info is copied into currentPlayer.
At the end of the turn, the scores are updated accordingly.
