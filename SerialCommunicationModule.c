//
// Created by Devin Morgan on 5/10/2017.
//

#include <stdio.h>
#include "SerialCommunicationModule.h"

void readPositionFromController(GameState* pGameState, BoardPosition* pPosition) {
    // TODO: implement me!
}

int scanForGamePlayMode() {
    int mode;
    scanf("%d", &mode);
    return mode;
}