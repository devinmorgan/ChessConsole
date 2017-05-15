//
// Created by Devin Morgan on 5/10/2017.
//

#include "ChessGameComponents/ChessBoard.h"
#include "GameStateModule.h"

#ifndef CHESSCONSOLE_SERIALCOMMUNICATIONMODULE_H
#define CHESSCONSOLE_SERIALCOMMUNICATIONMODULE_H

void readPositionFromController(GameState* pGameState, BoardPosition* pPosition);

int scanForGamePlayMode();

#endif //CHESSCONSOLE_SERIALCOMMUNICATIONMODULE_H
