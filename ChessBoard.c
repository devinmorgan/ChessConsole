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
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            switch(pChessBoard[i][j]) {
                case(ROOK_B) : printf("RO\t");
                    break;
                case(KNIGHT_B) : printf("KN\t");
                    break;
                case(BISHOP_B) : printf("BP\t");
                    break;
                case(QUEEN_B) : printf("QN\t");
                    break;
                case(KING_B) : printf("KG\t");
                    break;
                case(EMPTY) : printf("__\t");
                    break;
                case(ROOK_W) : printf("ro\t");
                    break;
                case(KNIGHT_W) : printf("kn\t");
                    break;
                case(BISHOP_W) : printf("bp\t");
                    break;
                case(QUEEN_W) : printf("qn\t");
                    break;
                case(KING_W) : printf("kg\t");
                    break;
            }
        }
        printf("\n");
    }
}