//
// Created by Devin Morgan on 5/9/2017.
//

#include <stdio.h>
#include "ChessBoard.h"
#include "ChessPiece.h"

bool validBoardLocation(Coordinate position) {
    return 0 < position.row && position.row < 8
           && 0 < position.col && position.col < 8;
}

void initializeChessBoard(BoardPosition chessBoard[8][8]) {

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Color positionColor = (i + j) % 2 == 0 ? WHITE : BLACK;

            // set up the BLACK pieces
            if (i < 2) {
                chessBoard[i][j] = {i,j, &blackPieces[8*i + j], positionColor, REGULAR};
            }

            // set up the empty middle rows
            else if (i < 6) {
                chessBoard[i][j] = {i,j, NULL, positionColor, REGULAR};
            }

            // set up the WHITE pieces
            else {
                chessBoard[i][j] = {i,j, &whitePieces[8*(i-6) + j], positionColor, REGULAR};
            }
        }
    }
}

void prettyPrintChessBoard(BoardPosition chessBoard[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            BoardPosition pos = chessBoard[i][j];
            if (pos.piece == NULL) {
                if (pos.color == WHITE) {
                    printf("__");
                }
                else {
                    printf(". .");
                }
            }
            else if (pos.piece->color == BLACK) {
                switch(pos.piece->type) {
                    case PAWN:
                        printf("p");
                        break;
                    case KNIGHT:
                        printf("n");
                        break;
                    case BISHOP:
                        printf("b");
                        break;
                    case ROOK:
                        printf("r");
                        break;
                    case QUEEN:
                        printf("q");
                        break;
                    case KING:
                        printf("k");
                        break;
                }
            }
            else {
                switch (pos.piece->type) {
                    case PAWN:
                        printf("P");
                        break;
                    case KNIGHT:
                        printf("N");
                        break;
                    case BISHOP:
                        printf("B");
                        break;
                    case ROOK:
                        printf("R");
                        break;
                    case QUEEN:
                        printf("Q");
                        break;
                    case KING:
                        printf("K");
                        break;
                }
            }
            printf("\t");
        }
        printf("\n");
    }
}

ChessPiece* getClosestPieceLeft(int row, int col, BoardPosition grid[8][8]) {
    if (row < 0 || 7 < row || col < 0 || 7 < col)
        return NULL;
    if ((grid[row][col]).piece != NULL)
        return (grid[row][col]).piece;
    else
        return getClosestPieceLeft(row, --col, grid);
}

ChessPiece* getClosestPieceUpperLeft(int row, int col, BoardPosition grid[8][8]) {
    if (row < 0 || 7 < row || col < 0 || 7 < col)
        return NULL;
    if ((grid[row][col]).piece != NULL)
        return (grid[row][col]).piece;
    else
        return getClosestPieceUpperLeft(--row, --col, grid);
}

ChessPiece* getClosestPieceUpper(int row, int col, BoardPosition grid[8][8]) {
    if (row < 0 || 7 < row || col < 0 || 7 < col)
        return NULL;
    if ((grid[row][col]).piece != NULL)
        return (grid[row][col]).piece;
    else
        return getClosestPieceUpper(--row, col, grid);
}

ChessPiece* getClosestPieceUpperRight(int row, int col, BoardPosition grid[8][8]) {
    if (row < 0 || 7 < row || col < 0 || 7 < col)
        return NULL;
    if ((grid[row][col]).piece != NULL)
        return (grid[row][col]).piece;
    else
        return getClosestPieceUpperRight(--row, ++col, grid);
}

ChessPiece* getClosestPieceRight(int row, int col, BoardPosition grid[8][8]) {
    if (row < 0 || 7 < row || col < 0 || 7 < col)
        return NULL;
    if ((grid[row][col]).piece != NULL)
        return (grid[row][col]).piece;
    else
        return getClosestPieceRight(row, ++col, grid);
}

ChessPiece* getClosestPieceLowerRight(int row, int col, BoardPosition grid[8][8]) {
    if (row < 0 || 7 < row || col < 0 || 7 < col)
        return NULL;
    if ((grid[row][col]).piece != NULL)
        return (grid[row][col]).piece;
    else
        return getClosestPieceLowerRight(--row, ++col, grid);
}

ChessPiece* getClosestPieceLower(int row, int col, BoardPosition grid[8][8]) {
    if (row < 0 || 7 < row || col < 0 || 7 < col)
        return NULL;
    if ((grid[row][col]).piece != NULL)
        return (grid[row][col]).piece;
    else
        return getClosestPieceLower(++row, col, grid);
}

ChessPiece* getClosestPieceLowerLeft(int row, int col, BoardPosition grid[8][8]) {
    if (row < 0 || 7 < row || col < 0 || 7 < col)
        return NULL;
    if ((grid[row][col]).piece != NULL)
        return (grid[row][col]).piece;
    else
        return getClosestPieceLowerLeft(--row, ++col, grid);
}

bool samePosition(Coordinate p1, Coordinate p2) {
    return p1.row == p2.row && p1.col == p2.col;
}