//
// Created by Devin Morgan on 5/15/2017.
//

#ifndef CHESSCONSOLE_CHESSPIECE_H
#define CHESSCONSOLE_CHESSPIECE_H


#include <stdbool.h>

typedef enum {
    BLACK, WHITE
} Color;

typedef struct {
    int row;
    int col;
} Coordinate;

typedef enum {
    PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING
} PieceType;

typedef struct{
    PieceType type;
    Color color;
    bool hasMoved;
    Coordinate boardPosition;
} ChessPiece;
// BLACK pieces
ChessPiece blackPieces[16] =
    {{ROOK,   BLACK, false, {0, 0}},
     {KNIGHT, BLACK, false, {0, 1}},
     {BISHOP, BLACK, false, {0, 2}},
     {QUEEN,  BLACK, false, {0, 3}},
     {KING,   BLACK, false, {0, 4}},
     {BISHOP, BLACK, false, {0, 5}},
     {KNIGHT, BLACK, false, {0, 6}},
     {ROOK,   BLACK, false, {0, 7}},
     {PAWN,   BLACK, false, {1, 0}},
     {PAWN,   BLACK, false, {1, 1}},
     {PAWN,   BLACK, false, {1, 2}},
     {PAWN,   BLACK, false, {1, 3}},
     {PAWN,   BLACK, false, {1, 4}},
     {PAWN,   BLACK, false, {1, 5}},
     {PAWN,   BLACK, false, {1, 6}},
     {PAWN,   BLACK, false, {1, 7}}
    };

// WHITE pieces
ChessPiece whitePieces[16] = {{PAWN,   WHITE, false, {6, 2}},
        {PAWN,   WHITE, false, {6, 3}},
        {PAWN,   WHITE, false, {6, 4}},
        {PAWN,   WHITE, false, {6, 5}},
        {PAWN,   WHITE, false, {6, 6}},
        {PAWN,   WHITE, false, {6, 7}},
        {{ROOK,  WHITE, false, {7, 0}},
        {KNIGHT, WHITE, false, {7, 1}},
        {BISHOP, WHITE, false, {7, 2}},
        {QUEEN,  WHITE, false, {7, 3}},
        {KING,   WHITE, false, {7, 4}},
        {BISHOP, WHITE, false, {7, 5}},
        {KNIGHT, WHITE, false, {7, 6}},
        {ROOK,   WHITE, false, {7, 7}}
    };

#endif //CHESSCONSOLE_CHESSPIECE_H
