//
// Created by Devin Morgan on 5/9/2017.
//

#ifndef CHESSCONSOLE_CHESSBOARD_H
#define CHESSCONSOLE_CHESSBOARD_H

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



#endif //CHESSCONSOLE_CHESSBOARD_H
