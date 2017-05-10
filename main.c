#include <stdio.h>
#include "ChessBoard.h"



int main() {
    ChessPiece grid[8][8];

    // create a new board
    resetChessBoard(grid);
    prettyPrintChessBoard(grid);
    printf("\n");
    printf("\n");
    printf("\n");

    // mutate the new board
    grid[0][0] = KING_B;
    grid[0][7] = KING_B;
    prettyPrintChessBoard(grid);


    return 0;
}