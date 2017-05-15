//
// Created by Devin Morgan on 5/10/2017.
//

#include <stdbool.h>
#include "HelperFiles/ChessBoard.h"
#include "HelperFiles/GameStateModuleHelperLibrary.h"

#ifndef CHESSCONSOLE_CHESSGAMESTATE_H
#define CHESSCONSOLE_CHESSGAMESTATE_H

typedef enum {
    TIMED, UNTIMED, EXIT
} PlayMode;

void playTimedChess();

void playUntimedChess();

PlayMode promptUserForGamePlayMode();

GameState* initializeUntimedChessGame();

void makeNextMove(GameState* pGameState);

#endif //CHESSCONSOLE_CHESSGAMESTATE_H
