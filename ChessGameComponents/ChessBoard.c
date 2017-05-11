//
// Created by Devin Morgan on 5/9/2017.
//

#include <stdio.h>
#include <ctype.h>
#include "ChessBoard.h"

#include "ChessBoard.h"

const static ChessPiece defaultGrid[8][8] = {
        {{ROOK, BLACK}, {KNIGHT, BLACK}, {BISHOP, BLACK}, {QUEEN, BLACK}, {KING, BLACK}, {BISHOP, BLACK}, {KNIGHT, BLACK}, {ROOK, BLACK}},
        {{PAWN, BLACK}, {PAWN, BLACK},   {PAWN, BLACK},   {PAWN, BLACK},  {PAWN, BLACK}, {PAWN, BLACK},   {PAWN, BLACK},   {PAWN, BLACK}},
        {{EMPTY, BLACK},{EMPTY, BLACK},  {EMPTY, BLACK},  {EMPTY, BLACK}, {EMPTY, BLACK},{EMPTY, BLACK},  {EMPTY, BLACK},  {EMPTY, BLACK}},
        {{EMPTY, BLACK},{EMPTY, BLACK},  {EMPTY, BLACK},  {EMPTY, BLACK}, {EMPTY, BLACK},{EMPTY, BLACK},  {EMPTY, BLACK},  {EMPTY, BLACK}},
        {{EMPTY, BLACK},{EMPTY, BLACK},  {EMPTY, BLACK},  {EMPTY, BLACK}, {EMPTY, BLACK},{EMPTY, BLACK},  {EMPTY, BLACK},  {EMPTY, BLACK}},
        {{EMPTY, BLACK},{EMPTY, BLACK},  {EMPTY, BLACK},  {EMPTY, BLACK}, {EMPTY, BLACK},{EMPTY, BLACK},  {EMPTY, BLACK},  {EMPTY, BLACK}},
        {{PAWN, WHITE}, {PAWN, WHITE},   {PAWN, WHITE},   {PAWN, WHITE},  {PAWN, WHITE}, {PAWN, WHITE},   {PAWN, WHITE},   {PAWN, WHITE}},
        {{ROOK, WHITE}, {KNIGHT, WHITE}, {BISHOP, WHITE}, {QUEEN, WHITE}, {KING, WHITE}, {BISHOP, WHITE}, {KNIGHT, WHITE}, {ROOK, WHITE}}
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