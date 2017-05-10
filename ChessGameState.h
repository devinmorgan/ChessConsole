//
// Created by Devin Morgan on 5/10/2017.
//

#include <stdbool.h>
#include "ChessBoard.h""

#ifndef CHESSCONSOLE_CHESSGAMESTATE_H
#define CHESSCONSOLE_CHESSGAMESTATE_H

typedef struct {
    ChessPiece grid[8][8];
    bool gameOver;
    bool isCheck;
    bool isWhitesMove;
    BoardPosition fromLoc;
    BoardPosition toLoc;
} ChessGameState;

void createNewChessGameState(ChessGameState *gameState);

void makeNextMove(ChessGameState *gameState);

#endif //CHESSCONSOLE_CHESSGAMESTATE_H
