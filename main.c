/* Liam Smyth's program that manages a game of Othello between 2 players */

#include "Assignment2.h"

int main() {

    int i, j;
    int turnScore; // variable that keeps track of how many tiles were converted on each turn
    char playerInput[3]; // character array used to record what the player enters as their move
    int playerChoice[2]; // integer array used to store the players move in the form of 2 integer values
    bool found;
    int counter = 0; // This variable will keep track of whether or not either player has a valid move
    int playerTurn = 0; // This variable will keep track of which players' turn it is currently

    for(i = 0; i < 10; i++)
    {
        /* Begin by initialising the outside of the board with -1 */
        board[0][i] = OUTSIDE;
        board[9][i] = OUTSIDE;
        board[i][0] = OUTSIDE;
        board[i][9] = OUTSIDE;
    }

    // Initialise the board with all empty spaces
    for(i = 1; i < 9; i++)
    {
        // outer loop loops over each row
        for(j = 1; j < 9; j++)
        {
            // inner loop loops over each column
            board[i][j] = EMPTY;
        }
    }

    // Initialise the middle of the board with 2 BLACKS and 2 WHITES
    board[5][5] = WHITE; board[5][4] = BLACK;
    board[4][4] = WHITE; board[4][5] = BLACK;

    // Initialize the players in the game
    struct Player player1;
    player1.colour = BLACK;
    player1.score = 2;

    struct Player player2;
    player2.colour = WHITE;
    player2.score = 2;

    struct Player currentPlayer;

    printf("\t\t***\tWelcome to Othello\t***\n\n"); //Introduce the players to the game

    // Ask the players to input their names
    printf("Enter name of player 1 (Black): ");
    fscanf(stdin, "%20s", player1.name);
    printf("\nEnter name of player 2 (White): ");
    fscanf(stdin, "%20s", player2.name);

    printBoard(player1, player2); // Print out the board for the Players

    // Play the game within this while loop
    while(player1.score + player2.score < 64 && counter != 2)
    {
        /* The game will end when either the board is full OR if neither player has a valid move */

        playerTurn = playerTurn % 2; // This statement keeps track of which players turn it is

        // The struct "currentPlayer" is used to hold the info of the current player
        if(playerTurn == 0)
        {
            currentPlayer = player1;
        }
        else
        {
            currentPlayer = player2;
        }

        // Firstly, check if there is any possible moves for the current player
        found = false;
        for(i = 1; i < 9; i++)
        {
            for(j = 0; j < 9; j++)
            {
                // Check every tile on the board to see if the current player can make a move
                if(isValid(i, j, currentPlayer.colour))
                {
                    found = true;
                }
            }
        }

        if(found == true)
        {
            // If the current player has a possible move(s), let them pick a move
            printf("\nIt is %s's turn\n", currentPlayer.name);
            printf("Please enter your move (in the form: number then lowercase letter): ");
            fscanf(stdin, "%2s", playerInput);

            // Convert the players' choice from a string into 2 integer values
            playerChoice[0] = convertInput(playerInput, 0);
            playerChoice[1] = convertInput(playerInput, 1);

            // If the player enters a tile that is not on the board, ask them to input another choice
            while((playerChoice[0] < 1) || (playerChoice[0] > 8) || (playerChoice[1] < 1) || (playerChoice[1] > 8))
            {
                printf("\nInvalid choice, enter a tile that is on the board: ");
                fscanf(stdin, "%2s", playerInput);

                // Convert the players' choice from a string into 2 integer values
                playerChoice[0] = convertInput(playerInput, 0);
                playerChoice[1] = convertInput(playerInput, 1);
            }

            /* Check to see if the player has inputted an invalid move and if they have, ask them
             * to make another choice */
            while(!(isValid(playerChoice[0], playerChoice[1], currentPlayer.colour)))
            {
                printf("\nInvalid move, please enter a valid move: ");
                fscanf(stdin, "%2s", playerInput);

                // Convert the players' choice from a string into 2 integer values
                playerChoice[0] = convertInput(playerInput, 0);
                playerChoice[1] = convertInput(playerInput, 1);
            }

            // Convert the tiles on the board the the current players' colour, depending on what move they made
            turnScore = convertTiles(playerChoice[0], playerChoice[1], currentPlayer.colour);

            // Update the both player's scores
            if(playerTurn == 0)
            {
                player1.score += turnScore + 1;
                player2.score -= turnScore;
            }
            else
            {
                player2.score += turnScore + 1;
                player1.score -= turnScore;
            }

            printBoard(player1, player2); // Print out the board for the Players

            counter = 0; // reset the counter to indicate that this player has had a valid move
            playerTurn++; // increment this variable so the next iteration of the game will be the other player's turn
        }

        else
        {
            /* Otherwise, if the current player does not have a valid move, increment
             * the counter and move onto the next player */
            printf("Player %d has no valid moves.\n", playerTurn + 1);
            counter++;
            playerTurn++;
        }
    }

    if(counter == 2)
    {
        printf("\nThe game has ended because neither player has a valid move.\n");
    }
    else
    {
        printf("\nThe game has ended because the board is full.\n");
    }

    if(player1.score > player2.score) // Player 1 is the winner
    {
        printf("%s is the winner with a score of %d\n", player1.name, player1.score);
    }
    else // Player 2 is the winner
    {
        printf("%s is the winner with a score of %d\n", player2.name, player2.score);
    }

    return 0;
}
