//
// Created by Devin Morgan on 5/9/2017.
//

#include <stdbool.h>

#ifndef CHESSCONSOLE_CHESSBOARD_H
#define CHESSCONSOLE_CHESSBOARD_H

// often represents the {delta cols, delta rows}
// with positive representing to the right for cols
// and downwards for rows. E.g. think about the game
// from WHITE's perspective
typedef struct {
    int x;
    int y;
} Coordinate;

typedef enum {
    BLACK, WHITE
} Color;

typedef enum {
    PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING, EMPTY
} PieceType;

typedef struct{
    PieceType type;
    Color color;
    bool hasMoved;
} ChessPiece;

typedef struct {
    int rowIndex;
    int colIndex;
} BoardPosition;

void resetChessBoard(ChessPiece pChessBoard[8][8]);

void prettyPrintChessBoard(ChessPiece pChessBoard[8][8]);

ChessPiece* getClosestPieceLeft(int row, int col, ChessPiece grid[8][8]);

ChessPiece* getClosestPieceUpperLeft(int row, int col, ChessPiece grid[8][8]);

ChessPiece* getClosestPieceUpper(int row, int col, ChessPiece grid[8][8]);

ChessPiece* getClosestPieceUpperRight(int row, int col, ChessPiece grid[8][8]);

ChessPiece* getClosestPieceRight(int row, int col, ChessPiece grid[8][8]);

ChessPiece* getClosestPieceLowerRight(int row, int col, ChessPiece grid[8][8]);

ChessPiece* getClosestPieceLower(int row, int col, ChessPiece grid[8][8]);

ChessPiece* getClosestPieceLowerLeft(int row, int col, ChessPiece grid[8][8]);

bool samePosition(BoardPosition p1, BoardPosition p2);



#endif //CHESSCONSOLE_CHESSBOARD_H
