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
    printf("Choose a piece (x or o) or q to quit: ");
    scanf("%c", &piece);
    printf("Choose a row (0-4): ");
    scanf("%d", &row);
    printf("Choose a column (0-4): ");
    scanf("%d", &col);
}

int main() {

    printGameBoard();
    printGamePrompts();
    
    

    /* Error Message: Invalid Values */
    if (piece != 'x' && piece != 'o' && piece != 'q') {
        printf("Invalid choice. Choose a piece (x or o) or q to quit: ");
        scanf("%c", &piece);
    }
    if (!(row >= 0 && row <= 4)) {
        printf("Invalid choice. Choose a row (0-4): ");
        scanf("%d", &row);
    }
    if (!(col >= 0 && col <= 4)) {
        printf("Invalid choice. Choose a column (0-4): ");
        scanf("%d", &col);
    }

    /* Error Message: Invalid Cell Choice */
    if (board[row][col] != '-') {
        printf("Invalid choice. That space is already occupied."); /* If the space is occupied, send an error message. */
    }

    /* Print the Winning Message */
    bool boardFilled = true;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; i < COLS; i++) {
            if(board[i][j] == '-') {
                boardFilled = false;
            }
        }
    }

    if (boardFilled == true) {
        printf("Congratulations, you have filled the board!");
    }

    return 0;
}

