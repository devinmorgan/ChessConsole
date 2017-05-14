//
// Created by Devin Morgan on 5/9/2017.
//

#include <stdio.h>
#include <ctype.h>
#include "ChessBoard.h"

const static ChessPiece defaultGrid[8][8] = {
        {{ROOK, BLACK, false}, {KNIGHT, BLACK, false}, {BISHOP, BLACK, false}, {QUEEN, BLACK, false}, {KING, BLACK, false}, {BISHOP, BLACK, false}, {KNIGHT, BLACK, false}, {ROOK, BLACK, false}},
        {{PAWN, BLACK, false}, {PAWN, BLACK, false},   {PAWN, BLACK, false},   {PAWN, BLACK, false},  {PAWN, BLACK, false}, {PAWN, BLACK, false},   {PAWN, BLACK, false},   {PAWN, BLACK, false}},
        {{EMPTY, BLACK, false},{EMPTY, BLACK, false},  {EMPTY, BLACK, false},  {EMPTY, BLACK, false}, {EMPTY, BLACK, false},{EMPTY, BLACK, false},  {EMPTY, BLACK, false},  {EMPTY, BLACK, false}},
        {{EMPTY, BLACK, false},{EMPTY, BLACK, false},  {EMPTY, BLACK, false},  {EMPTY, BLACK, false}, {EMPTY, BLACK, false},{EMPTY, BLACK, false},  {EMPTY, BLACK, false},  {EMPTY, BLACK, false}},
        {{EMPTY, BLACK, false},{EMPTY, BLACK, false},  {EMPTY, BLACK, false},  {EMPTY, BLACK, false}, {EMPTY, BLACK, false},{EMPTY, BLACK, false},  {EMPTY, BLACK, false},  {EMPTY, BLACK, false}},
        {{EMPTY, BLACK, false},{EMPTY, BLACK, false},  {EMPTY, BLACK, false},  {EMPTY, BLACK, false}, {EMPTY, BLACK, false},{EMPTY, BLACK, false},  {EMPTY, BLACK, false},  {EMPTY, BLACK, false}},
        {{PAWN, WHITE, false}, {PAWN, WHITE, false},   {PAWN, WHITE, false},   {PAWN, WHITE, false},  {PAWN, WHITE, false}, {PAWN, WHITE, false},   {PAWN, WHITE, false},   {PAWN, WHITE, false}},
        {{ROOK, WHITE, false}, {KNIGHT, WHITE, false}, {BISHOP, WHITE, false}, {QUEEN, WHITE, false}, {KING, WHITE, false}, {BISHOP, WHITE, false}, {KNIGHT, WHITE, false}, {ROOK, WHITE, false}}
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
            char letter;
            switch(pChessBoard[i][j].type) {
                case(PAWN) : letter = 'P';
                    break;
                case(ROOK) : letter = 'R';
                    break;
                case(KNIGHT) : letter = 'N';
                    break;
                case(BISHOP) : letter = 'B';
                    break;
                case(QUEEN) : letter = 'Q';
                    break;
                case(KING) : letter = 'K';
                    break;
                case(EMPTY) : letter = ' ';
                    break;
                default: letter = '$';
                    break;
            }
            if (pChessBoard[i][j].color == WHITE) letter = tolower(letter);
            printf("%c\t",letter);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
    printf("\n");
}

ChessPiece* getClosestPieceLeft(int row, int col, ChessPiece grid[8][8]) {
    if (row < 0 || 7 < row || col < 0 || 7 < col)
        return NULL;
    if (grid[row][col].type != EMPTY)
        return &grid[row][col];
    else
        return getClosestPieceLeft(row, --col, grid);
}

ChessPiece* getClosestPieceUpperLeft(int row, int col, ChessPiece grid[8][8]) {
    if (row < 0 || 7 < row || col < 0 || 7 < col)
        return NULL;
    if (grid[row][col].type != EMPTY)
        return &grid[row][col];
    else
        return getClosestPieceUpperLeft(--row, --col, grid);
}

ChessPiece* getClosestPieceUpper(int row, int col, ChessPiece grid[8][8]) {
    if (row < 0 || 7 < row || col < 0 || 7 < col)
        return NULL;
    if (grid[row][col].type != EMPTY)
        return &grid[row][col];
    else
        return getClosestPieceUpper(--row, col, grid);
}

ChessPiece* getClosestPieceUpperRight(int row, int col, ChessPiece grid[8][8]) {
    if (row < 0 || 7 < row || col < 0 || 7 < col)
        return NULL;
    if (grid[row][col].type != EMPTY)
        return &grid[row][col];
    else
        return getClosestPieceUpperRight(--row, ++col, grid);
}

ChessPiece* getClosestPieceRight(int row, int col, ChessPiece grid[8][8]) {
    if (row < 0 || 7 < row || col < 0 || 7 < col)
        return NULL;
    if (grid[row][col].type != EMPTY)
        return &grid[row][col];
    else
        return getClosestPieceRight(row, ++col, grid);
}

ChessPiece* getClosestPieceLowerRight(int row, int col, ChessPiece grid[8][8]) {
    if (row < 0 || 7 < row || col < 0 || 7 < col)
        return NULL;
    if (grid[row][col].type != EMPTY)
        return &grid[row][col];
    else
        return getClosestPieceLowerRight(--row, ++col, grid);
}

ChessPiece* getClosestPieceLower(int row, int col, ChessPiece grid[8][8]) {
    if (row < 0 || 7 < row || col < 0 || 7 < col)
        return NULL;
    if (grid[row][col].type != EMPTY)
        return &grid[row][col];
    else
        return getClosestPieceLower(++row, col, grid);
}

ChessPiece* getClosestPieceLowerLeft(int row, int col, ChessPiece grid[8][8]) {
    if (row < 0 || 7 < row || col < 0 || 7 < col)
        return NULL;
    if (grid[row][col].type != EMPTY)
        return &grid[row][col];
    else
        return getClosestPieceLowerLeft(--row, ++col, grid);
}

bool samePosition(BoardPosition p1, BoardPosition p2) {
    return p1.rowIndex == p2.rowIndex && p1.colIndex == p2.colIndex;
}