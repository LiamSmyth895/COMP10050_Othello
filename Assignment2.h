/* Liam Smyth's header file for functions and declarations used in Assignment 2 */

#ifndef ASSIGNMENT2_ASSIGNMENT2_H
#define ASSIGNMENT2_ASSIGNMENT2_H
#endif //ASSIGNMENT2_ASSIGNMENT2_H

#include <stdio.h>
#include <stdbool.h>

// Define Black, White and Empty spaces as integers
#define WHITE 2
#define BLACK 1
#define EMPTY 0
#define OUTSIDE -1

// Declare the array for the game board
int board[10][10];

// Declare the structs that contain the player information
struct Player {
    char name[21];
    int score;
    int colour;
};

static char seperator[] = "\t   --- --- --- --- --- --- --- --- ";

void printBoard(struct Player player1, struct Player player2);

/* These functions will be used to determine whether or not move is Valid.
 * The capital letters at the end of each function indicate what direction that function is checking
 * e.g NW means North West and S means South */
bool isValid(int i, int j, int currentColour);
bool isValidN(int i, int j, int currentColour);
bool isValidNE(int i, int j, int currentColour);
bool isValidE(int i, int j, int currentColour);
bool isValidSE(int i, int j, int currentColour);
bool isValidS(int i, int j, int currentColour);
bool isValidSW(int i, int j, int currentColour);
bool isValidW(int i, int j, int currentColour);
bool isValidNW(int i, int j, int currentColour);

int convertInput(char playerInput[], int i); // Converts the players move choice from a string to an integer

int convertTiles(int i, int j, int currentColour); // Converts tiles on the board, depending on the players move


