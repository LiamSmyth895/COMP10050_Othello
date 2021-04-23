/* Liam Smyth's C source code file for functions required in Assignment 2 */

#include "Assignment2.h"

void printBoard(struct Player player1, struct Player player2)
{
    /* This function prints out the current state of the board and the player's scores */

    int i, j;
    // Begin by printing out the names and scores of the players
    printf("\n\tScore: %s (Black) %d:%d %s (White)\n", player1.name, player1.score, player2.score, player2.name);

    // Print out the board in a consistent format
    printf("%s\n", seperator);
    for(i = 1; i < 9; i++)
    {
        // outer loops prints each row
        printf("\t%d | ", i);
        for(j = 1; j < 9; j++)
        {
            // inner loop prints each column
            if(board[i][j] == WHITE)
            {
                printf("W | ");
            }
            else if(board[i][j] == BLACK)
            {
                printf("B | ");
            }
            else
            {
                printf("  | ");
            }
        }
        printf("\n%s\n", seperator);

    }

    printf("\t\ta\tb\tc\td\te\tf\tg\th\n");
}// End of printBoard function

bool isValid(int i, int j, int currentColour)
{
    /* This is the top function for checking whether or not a move is valid */
    // Firstly check if the chosen tile is occupied
    if(board[i][j] != EMPTY)
    {
        return false;
    }
    else // Otherwise check each direction to decide whether or not this is a valid move
    {
        if(isValidN(i, j, currentColour))
        {
            return true;
        }
        else if(isValidNE(i, j, currentColour))
        {
            return true;
        }
        else if(isValidE(i, j, currentColour))
        {
            return true;
        }
        else if(isValidSE(i, j, currentColour))
        {
            return true;
        }
        else if(isValidS(i, j, currentColour))
        {
            return true;
        }
        else if(isValidSW(i, j, currentColour))
        {
            return true;
        }
        else if(isValidW(i, j, currentColour))
        {
            return true;
        }
        else if(isValidNW(i, j, currentColour))
        {
            return true;
        }
    }
    // If this is not a possible direction in any direction, then this is not a valid move
    return false;
} // End if isValid function

bool isValidN(int i, int j, int currentColour)
{
    // Function to check if this move is valid in a Northern direction
    bool valid, found = false;
    i++; // move the chosen tile up by 1
    if(board[i][j] == EMPTY || board[i][j] == OUTSIDE || board[i][j] == currentColour)
    {
        /* If the tile above the chosen tile is empty OR is empty OR is the same colour, then
         * this is not a valid move */
        return false;
    }
    else // Otherwise, this is possibly a valid move
    {
        valid = true;
        while(valid && !found)
        {
            i++; // move the tile up by 1
            if(board[i][j] == EMPTY || board[i][j] == OUTSIDE)
            {
                valid = false; // If we find a tile that is empty or outside the board, then this is not a valid move
            }
            else if(board[i][j] == currentColour)
            {
                found = true; // If we find another tile that is the same colour, then this is a valid move
            }
        }
    }
    return valid;
} // End of isValidN function

bool isValidNE(int i, int j, int currentColour)
{
    // Function to check if this move is valid in a North Eastern direction
    bool valid, found = false;
    i++; j++; // move the chosen tile up by 1 and right by 1
    if(board[i][j] == EMPTY || board[i][j] == OUTSIDE || board[i][j] == currentColour)
    {
        /* If the tile above the chosen tile is empty OR is empty OR is the same colour, then
         * this is not a valid move */
        return false;
    }
    else // Otherwise, this is possibly a valid move
    {
        valid = true;
        while(valid && !found)
        {
            i++; j++; // move the chosen tile up by 1 and right by 1
            if(board[i][j] == EMPTY || board[i][j] == OUTSIDE)
            {
                valid = false; // If we find a tile that is empty or outside the board, then this is not a valid move
            }
            else if(board[i][j] == currentColour)
            {
                found = true; // If we find another tile that is the same colour, then this is a valid move
            }
        }
    }
    return valid;
}// End of isValidNE function

bool isValidE(int i, int j, int currentColour)
{
    // Function to check if this move is valid in a North Eastern direction
    bool valid, found = false;
    j++; // move the chosen tile right by 1
    if(board[i][j] == EMPTY || board[i][j] == OUTSIDE || board[i][j] == currentColour)
    {
        /* If the tile above the chosen tile is empty OR is empty OR is the same colour, then
         * this is not a valid move */
        return false;
    }
    else // Otherwise, this is possibly a valid move
    {
        valid = true;
        while(valid && !found)
        {
            j++; // move the chosen tile right by 1
            if(board[i][j] == EMPTY || board[i][j] == OUTSIDE)
            {
                valid = false; // If we find a tile that is empty or outside the board, then this is not a valid move
            }
            else if(board[i][j] == currentColour)
            {
                found = true; // If we find another tile that is the same colour, then this is a valid move
            }
        }
    }
    return valid;
} // End of isValidE function

bool isValidSE(int i, int j, int currentColour)
{
    // Function to check if this move is valid in a North Eastern direction
    bool valid, found = false;
    i--; j++; // move the chosen tile down by 1 and right by 1
    if(board[i][j] == EMPTY || board[i][j] == OUTSIDE || board[i][j] == currentColour)
    {
        /* If the tile above the chosen tile is empty OR is empty OR is the same colour, then
         * this is not a valid move */
        return false;
    }
    else // Otherwise, this is possibly a valid move
    {
        valid = true;
        while(valid && !found)
        {
            i--; j++; // move the chosen tile down by 1 and right by 1
            if(board[i][j] == EMPTY || board[i][j] == OUTSIDE)
            {
                valid = false; // If we find a tile that is empty or outside the board, then this is not a valid move
            }
            else if(board[i][j] == currentColour)
            {
                found = true; // If we find another tile that is the same colour, then this is a valid move
            }
        }
    }
    return valid;
} // End of isValidSE function

bool isValidS(int i, int j, int currentColour)
{
    // Function to check if this move is valid in a North Eastern direction
    bool valid, found = false;
    i--; // move the chosen tile down by 1
    if(board[i][j] == EMPTY || board[i][j] == OUTSIDE || board[i][j] == currentColour)
    {
        /* If the tile above the chosen tile is empty OR is empty OR is the same colour, then
         * this is not a valid move */
        return false;
    }
    else // Otherwise, this is possibly a valid move
    {
        valid = true;
        while(valid && !found)
        {
            i--; // move the chosen tile down by 1
            if(board[i][j] == EMPTY || board[i][j] == OUTSIDE)
            {
                valid = false; // If we find a tile that is empty or outside the board, then this is not a valid move
            }
            else if(board[i][j] == currentColour)
            {
                found = true; // If we find another tile that is the same colour, then this is a valid move
            }
        }
    }
    return valid;
} // End of isValidS function

bool isValidSW(int i, int j, int currentColour)
{
    // Function to check if this move is valid in a North Eastern direction
    bool valid, found = false;
    i--; j--; // move the chosen tile down by 1 and left by 1
    if(board[i][j] == EMPTY || board[i][j] == OUTSIDE || board[i][j] == currentColour)
    {
        /* If the tile above the chosen tile is empty OR is empty OR is the same colour, then
         * this is not a valid move */
        return false;
    }
    else // Otherwise, this is possibly a valid move
    {
        valid = true;
        while(valid && !found)
        {
            i--; j--; // move the chosen tile down by 1 and left by 1
            if(board[i][j] == EMPTY || board[i][j] == OUTSIDE)
            {
                valid = false; // If we find a tile that is empty or outside the board, then this is not a valid move
            }
            else if(board[i][j] == currentColour)
            {
                found = true; // If we find another tile that is the same colour, then this is a valid move
            }
        }
    }
    return valid;
} // End of isValidSW function

bool isValidW(int i, int j, int currentColour)
{
    // Function to check if this move is valid in a North Eastern direction
    bool valid, found = false;
    j--; // move the chosen tile left by 1
    if(board[i][j] == EMPTY || board[i][j] == OUTSIDE || board[i][j] == currentColour)
    {
        /* If the tile above the chosen tile is empty OR is empty OR is the same colour, then
         * this is not a valid move */
        return false;
    }
    else // Otherwise, this is possibly a valid move
    {
        valid = true;
        while(valid && !found)
        {
            j--; // move the chosen tile left by 1
            if(board[i][j] == EMPTY || board[i][j] == OUTSIDE)
            {
                valid = false; // If we find a tile that is empty or outside the board, then this is not a valid move
            }
            else if(board[i][j] == currentColour)
            {
                found = true; // If we find another tile that is the same colour, then this is a valid move
            }
        }
    }
    return valid;
} // End of isValidW function

bool isValidNW(int i, int j, int currentColour)
{
    // Function to check if this move is valid in a North Eastern direction
    bool valid, found = false;
    i++; j--; // move the chosen tile up by 1 and left by 1
    if(board[i][j] == EMPTY || board[i][j] == OUTSIDE || board[i][j] == currentColour)
    {
        /* If the tile above the chosen tile is empty OR is empty OR is the same colour, then
         * this is not a valid move */
        return false;
    }
    else // Otherwise, this is possibly a valid move
    {
        valid = true;
        while(valid && !found)
        {
            i++; j--; // move the chosen tile up by 1 and left by 1
            if(board[i][j] == EMPTY || board[i][j] == OUTSIDE)
            {
                valid = false; // If we find a tile that is empty or outside the board, then this is not a valid move
            }
            else if(board[i][j] == currentColour)
            {
                found = true; // If we find another tile that is the same colour, then this is a valid move
            }
        }
    }
    return valid;
} // End of isValidNW function

int convertInput(char playerInput[], int i)
{
    /* Function that converts the players move choice from a string to an integer */
    int output;
    if(i == 0) // If the second argument is equal to 0, then the first argument is a character integer
    {
        output = playerInput[i] - '0';
    }
    else // Otherwise, the first argument is a alphabetical character between a and h (inclusive)
    {
        /* Since 97 is the ascii number for the letter 'a', taking away 96 from the players'
         * input will leave us with an integer between 1 and 8 (inclusive) */
        output = playerInput[i] - 96;
    }

    return output;
} // End of convertInput function

int convertTiles(int i, int j, int currentColour)
{
    /* This function will take in a players chosen move, convert all the tiles necessary to
     * complete the move and return an integer that contains the the number of tiles that have been converted */

    int k = 0; // Keeps track of how many tiles have been converted, including the chosen tile
    int p, q; // used to index the current position on the board

    /* Check each direction to see what direction this move is valid for and for each valid
     * direction, convert all of the valid tiles in that direction */
    if(isValidN(i, j, currentColour))
    {
        p = i + 1; q = j;
        while(board[p][q] != currentColour)
        {
            /* While the current tile is not equal to the current colour, convert the current tile
             * and move onto the next tile. Keep track of how many tiles have been converted */
            board[p][q] = currentColour;
            k++;
            p++; // move the current tile up by 1
        }
    }
    if(isValidNE(i, j, currentColour))
    {
        p = i + 1; q = j + 1;
        while(board[p][q] != currentColour)
        {
            /* While the current tile is not equal to the current colour, convert the current tile
             * and move onto the next tile. Keep track of how many tiles have been converted */
            board[p][q] = currentColour;
            k++;
            p++; q++; // move the current tile up by 1 and right by 1
        }
    }
    if(isValidE(i, j, currentColour))
    {
        p = i; q = j + 1;
        while(board[p][q] != currentColour)
        {
            /* While the current tile is not equal to the current colour, convert the current tile
             * and move onto the next tile. Keep track of how many tiles have been converted */
            board[p][q] = currentColour;
            k++;
            q++; // move the current tile right by 1
        }
    }
    if(isValidSE(i, j, currentColour))
    {
        p = i - 1; q = j + 1;
        while(board[p][q] != currentColour)
        {
            /* While the current tile is not equal to the current colour, convert the current tile
             * and move onto the next tile. Keep track of how many tiles have been converted */
            board[p][q] = currentColour;
            k++;
            p--; q++; // move the current tile down by 1 and right by 1
        }
    }
    if(isValidS(i, j, currentColour))
    {
        p = i - 1; q = j;
        while(board[p][q] != currentColour)
        {
            /* While the current tile is not equal to the current colour, convert the current tile
             * and move onto the next tile. Keep track of how many tiles have been converted */
            board[p][q] = currentColour;
            k++;
            p--; // move the current tile down by 1
        }
    }
    if(isValidSW(i, j, currentColour))
    {
        p = i - 1; q = j - 1;
        while(board[p][q] != currentColour)
        {
            /* While the current tile is not equal to the current colour, convert the current tile
             * and move onto the next tile. Keep track of how many tiles have been converted */
            board[p][q] = currentColour;
            k++;
            p--; q--; // move the current tile down by 1 and left by 1
        }
    }
    if(isValidW(i, j, currentColour))
    {
        p = i; q = j - 1;
        while(board[p][q] != currentColour)
        {
            /* While the current tile is not equal to the current colour, convert the current tile
             * and move onto the next tile. Keep track of how many tiles have been converted */
            board[p][q] = currentColour;
            k++;
            q--; // move the current tile and left by 1
        }
    }
    if(isValidNW(i, j, currentColour))
    {
        p = i + 1; q = j - 1;
        while(board[p][q] != currentColour)
        {
            /* While the current tile is not equal to the current colour, convert the current tile
             * and move onto the next tile. Keep track of how many tiles have been converted */
            board[p][q] = currentColour;
            k++;
            p++; q--; // move the current tile up by 1 and left by 1
        }
    }

    board[i][j] = currentColour; // convert the chosen tile to the current colour

    return k;
} // End of convertTiles function