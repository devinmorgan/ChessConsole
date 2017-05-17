//
// Created by Devin Morgan on 5/10/2017.
//

#include "GameStateModule.h"

#ifndef CHESSCONSOLE_SERIALCOMMUNICATIONMODULE_H
#define CHESSCONSOLE_SERIALCOMMUNICATIONMODULE_H

void readPositionFromController(Coordinate* pCoordinate, GameState gameState);

int scanForGamePlayMode();

#endif //CHESSCONSOLE_SERIALCOMMUNICATIONMODULE_H
