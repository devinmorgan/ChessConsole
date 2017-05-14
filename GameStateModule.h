//
// Created by Devin Morgan on 5/10/2017.
//

#include <stdbool.h>
#include "HelperFiles/ChessBoard.h"

#ifndef CHESSCONSOLE_CHESSGAMESTATE_H
#define CHESSCONSOLE_CHESSGAMESTATE_H

typedef struct {
    ChessPiece piece;
    BoardPosition start;
    BoardPosition end;
} PlayerMove;

typedef struct {
    ChessPiece grid[8][8];
    Color teamColor;
    bool canMove;
    bool inCheck;
    bool gameOver;
    PlayerMove currentMove;
    PlayerMove lastMove;
} GameState;

void createNewChessGameState(GameState* pGameState);

void makeNextMove(GameState* pGameState);

#endif //CHESSCONSOLE_CHESSGAMESTATE_H
