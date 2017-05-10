//
// Created by Devin Morgan on 5/9/2017.
//

#include <stdio.h>
#include "ChessBoard.h"

#include "ChessBoard.h"

const static ChessPiece defaultGrid[8][8] = {
        {ROOK_B, KNIGHT_B, BISHOP_B, QUEEN_B, KING_B, BISHOP_B, KNIGHT_B, ROOK_B},
        {PAWN_B, PAWN_B,   PAWN_B,   PAWN_B,  PAWN_B, PAWN_B,   PAWN_B,   PAWN_B},
        {EMPTY,  EMPTY,    EMPTY,    EMPTY,   EMPTY,  EMPTY,    EMPTY,    EMPTY},
        {EMPTY,  EMPTY,    EMPTY,    EMPTY,   EMPTY,  EMPTY,    EMPTY,    EMPTY},
        {EMPTY,  EMPTY,    EMPTY,    EMPTY,   EMPTY,  EMPTY,    EMPTY,    EMPTY},
        {EMPTY,  EMPTY,    EMPTY,    EMPTY,   EMPTY,  EMPTY,    EMPTY,    EMPTY},
        {PAWN_W, PAWN_W,   PAWN_W,   PAWN_W,  PAWN_W, PAWN_W,   PAWN_W,   PAWN_W},
        {ROOK_W, KNIGHT_W, BISHOP_W, QUEEN_W, KING_W, BISHOP_W, KNIGHT_W, ROOK_W}
};

void resetChessBoard(ChessPiece pChessBoard[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            pChessBoard[i][j] = defaultGrid[i][j];
        }
    }
}

void prettyPrintChessBoard(ChessPiece pChessBoard[8][8]) {
    // print the column numbers
    printf("  %d",1);
    for (int i = 2; i <= 8; i++) printf("\t%d", i);
    printf("\n");

    for (int i = 0; i < 8; i++) {

        // print row numbers
        printf("%d ", i+1);

        // print the board layout
        for (int j = 0; j < 8; j++) {
            switch(pChessBoard[i][j]) {
                case(PAWN_B) : printf("P\t");
                    break;
                case(ROOK_B) : printf("R\t");
                    break;
                case(KNIGHT_B) : printf("N\t");
                    break;
                case(BISHOP_B) : printf("B\t");
                    break;
                case(QUEEN_B) : printf("Q\t");
                    break;
                case(KING_B) : printf("K\t");
                    break;
                case(EMPTY) : printf("_\t");
                    break;
                case(PAWN_W) : printf("p\t");
                    break;
                case(ROOK_W) : printf("r\t");
                    break;
                case(KNIGHT_W) : printf("n\t");
                    break;
                case(BISHOP_W) : printf("b\t");
                    break;
                case(QUEEN_W) : printf("q\t");
                    break;
                case(KING_W) : printf("k\t");
                    break;
            }
        }
        printf("\n");
    }
}