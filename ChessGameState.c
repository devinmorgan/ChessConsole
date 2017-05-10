//
// Created by Devin Morgan on 5/10/2017.
//

#include "ChessGameState.h"

void createNewChessGameState(ChessGameState *gameState) {
    resetChessBoard(gameState->grid);
    gameState->gameOver = false;
    gameState->isWhitesMove = true;
}