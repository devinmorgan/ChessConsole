//
// Created by Devin Morgan on 5/10/2017.
//

#include <stdbool.h>
#include "HelperFiles/ChessBoard.h"
#include "HelperFiles/GameStateModuleHelperLibrary.h"

#ifndef CHESSCONSOLE_CHESSGAMESTATE_H
#define CHESSCONSOLE_CHESSGAMESTATE_H

void createNewChessGameState(GameState* pGameState);

void makeNextMove(GameState* pGameState);

#endif //CHESSCONSOLE_CHESSGAMESTATE_H
