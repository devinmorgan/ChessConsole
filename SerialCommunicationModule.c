//
// Created by Devin Morgan on 5/10/2017.
//

#include <stdio.h>
#include "SerialCommunicationModule.h"

Coordinate readPositionFromController(GameState gameState) {
    int row, col;
    scanf("%d%d", &row, &col);
    return {row, col};
}

int scanForGamePlayMode() {
    int mode;
    scanf("%d", &mode);
    return mode;
}