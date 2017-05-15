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

#endif //CHESSCONSOLE_CHESSPIECE_H
