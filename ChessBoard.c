//
// Created by Devin Morgan on 5/9/2017.
//
#include "ChessBoard.h"



void resetChessBoard(ChessPiece* pChessBoard) {
    pChessBoard = {
            {ROOK_B, KNIGHT_B, BISHOP_B, QUEEN_B, KING_B, BISHOP_B, KNIGHT_B, ROOK_B},
            {PAWN_B, PAWN_B,   PAWN_B,   PAWN_B,  PAWN_B, PAWN_B,   PAWN_B,   PAWN_B},
            {EMPTY,  EMPTY,    EMPTY,    EMPTY,   EMPTY,  EMPTY,    EMPTY,    EMPTY},
            {EMPTY,  EMPTY,    EMPTY,    EMPTY,   EMPTY,  EMPTY,    EMPTY,    EMPTY},
            {EMPTY,  EMPTY,    EMPTY,    EMPTY,   EMPTY,  EMPTY,    EMPTY,    EMPTY},
            {EMPTY,  EMPTY,    EMPTY,    EMPTY,   EMPTY,  EMPTY,    EMPTY,    EMPTY},
            {ROOK_W, KNIGHT_W, BISHOP_W, QUEEN_W, KING_W, BISHOP_W, KNIGHT_W, ROOK_W},
            {PAWN_W, PAWN_W,   PAWN_W,   PAWN_W,  PAWN_W, PAWN_W,   PAWN_W,   PAWN_W},
    };
}