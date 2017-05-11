//
// Created by Devin Morgan on 5/9/2017.
//

#ifndef CHESSCONSOLE_CHESSBOARD_H
#define CHESSCONSOLE_CHESSBOARD_H

typedef enum {
    BLACK, WHITE, BLANK
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



#endif //CHESSCONSOLE_CHESSBOARD_H
