#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 5

char board[ROWS][COLS] = {
    {'x', 'x', 'x', '-', 'o'}, 
    {'o', 'x', 'x', 'o', 'o'}, 
    {'o', 'x', '-', 'x', 'x'}, 
    {'o', '-', 'x', 'x', '-'}, 
    {'x', 'o', 'x', 'o', 'o'}};

/* PROMPT ENTRIES */
char piece;
int row;
int col;

/* Hint:

scanf(" %c", &choice); //this command will erase whitespace in the token selection

*/

void printGameBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void printGamePrompts() {
    /* Choose a piece */
    printf("Choose a piece (x or o) or q to quit: ");
    scanf(" %c", &piece);

    if (piece != 'x' && piece != 'o' && piece != 'q') {
        printf("Invalid choice. Choose a piece (x or o) or q to quit: ");
        scanf(" %c", &piece);
    }

    /* Choose a row */
    printf("Choose a row (0-4): ");
    scanf(" %d", &row);

    if (!(row >= 0 && row <= 4)) {
        printf("Invalid choice. Choose a row (0-4): ");
        scanf(" %d", &row);
    }

    /* Choose a column */
    printf("Choose a column (0-4): ");
    scanf(" %d", &col);

    if (!(col >= 0 && col <= 4)) {
        printf("Invalid choice. Choose a column (0-4): ");
        scanf(" %d", &col);
    }

    /* Check if the chosen space is filled */
    if (board[row][col] != '-') {
        printf("Invalid choice. That space is already occupied.");
    } else {
        printGameBoard();
        printGamePrompts();
    }
}

void isBoardFilled() {
    bool filled = true;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; i < COLS; i++) {
            if(board[i][j] == '-') {
                filled = false;
            }
        }
    }

    if (filled == true) {
        printf("Congratulations, you have filled the board!");
    }
}

int main() {

    printGameBoard();
    printGamePrompts();
    isBoardFilled();
    
    return 0;
}

