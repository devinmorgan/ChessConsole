//
// Created by Devin Morgan on 5/9/2017.
//

#include <stdio.h>
#include <ctype.h>
#include "ChessBoard.h"

void initializeChessBoard(BoardPosition chessBoard[8][8]) {
   // BLACK pieces
    ChessPiece leftBlackRook = {ROOK, BLACK, false, {0, 0}};
    ChessPiece leftBlackKnight = {KNIGHT, BLACK, false, {0, 1}};
    ChessPiece leftBlackBishop = {BISHOP, BLACK, false, {0, 2}};
    ChessPiece blackQueen = {QUEEN, BLACK, false, {0, 3}};
    ChessPiece blackKing = {KING, BLACK, false, {0, 4}};
    ChessPiece rightBlackBishop = {BISHOP, BLACK, false, {0, 5}};
    ChessPiece rightBlackKnight = {KNIGHT, BLACK, false, {0, 6}};
    ChessPiece rightBlackRook = {ROOK, BLACK, false, {0, 7}};
    ChessPiece blackPawn1 = {PAWN, BLACK, false, {1, 0}};
    ChessPiece blackPawn2 = {PAWN, BLACK, false, {1, 1}};
    ChessPiece blackPawn3 = {PAWN, BLACK, false, {1, 2}};
    ChessPiece blackPawn4 = {PAWN, BLACK, false, {1, 3}};
    ChessPiece blackPawn5 = {PAWN, BLACK, false, {1, 4}};
    ChessPiece blackPawn6 = {PAWN, BLACK, false, {1, 5}};
    ChessPiece blackPawn7 = {PAWN, BLACK, false, {1, 6}};
    ChessPiece blackPawn8 = {PAWN, BLACK, false, {1, 7}};
    ChessPiece blackPieces[16] =
            {leftBlackRook, leftBlackKnight, leftBlackBishop, blackQueen, blackKing, rightBlackBishop, rightBlackKnight, rightBlackRook,
             blackPawn1, blackPawn2, blackPawn3, blackPawn4, blackPawn5, blackPawn6, blackPawn6, blackPawn7};

    // WHITE pieces
    ChessPiece whitePawn1 = {PAWN, WHITE, false, {6, 0}};
    ChessPiece whitePawn2 = {PAWN, WHITE, false, {6, 1}};
    ChessPiece whitePawn3 = {PAWN, WHITE, false, {6, 2}};
    ChessPiece whitePawn4 = {PAWN, WHITE, false, {6, 3}};
    ChessPiece whitePawn5 = {PAWN, WHITE, false, {6, 4}};
    ChessPiece whitePawn6 = {PAWN, WHITE, false, {6, 5}};
    ChessPiece whitePawn7 = {PAWN, WHITE, false, {6, 6}};
    ChessPiece whitePawn8 = {PAWN, WHITE, false, {6, 7}};
    ChessPiece leftWhiteRook = {ROOK, WHITE, false, {7, 0}};
    ChessPiece leftWhiteKnight = {KNIGHT, WHITE, false, {7, 1}};
    ChessPiece leftWhiteBishop = {BISHOP, WHITE, false, {7, 2}};
    ChessPiece WhiteQueen = {QUEEN, WHITE, false, {7, 3}};
    ChessPiece WhiteKing = {KING, WHITE, false, {7, 4}};
    ChessPiece rightWhiteBishop = {BISHOP, WHITE, false, {7, 5}};
    ChessPiece rightWhiteKnight = {KNIGHT, WHITE, false, {7, 6}};
    ChessPiece rightWhiteRook = {ROOK, WHITE, false, {7, 7}};
    ChessPiece whitePieces[16] =
            {leftWhiteRook, leftWhiteKnight, leftWhiteBishop, WhiteQueen, WhiteKing, rightWhiteBishop, rightWhiteKnight, rightWhiteRook,
             whitePawn1, whitePawn2, whitePawn3, whitePawn4, whitePawn5, whitePawn6, whitePawn6, whitePawn7};

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Color positionColor = (i + j) % 2 == 0 ? WHITE : BLACK;

            // set up the BLACK pieces
            if (i < 2) {
                chessBoard[i][j] = {i,j, &blackPieces[8*i + j], positionColor, false};
            }

            // set up the empty middle rows
            else if (i < 6) {
                chessBoard[i][j] = {i,j, NULL, positionColor, false};
            }

            // set up the WHITE pieces
            else {
                chessBoard[i][j] = {i,j, &whitePieces[8*(i-6) + j], positionColor, false};
            }
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