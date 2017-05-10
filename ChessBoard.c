//
// Created by Devin Morgan on 5/9/2017.
//

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