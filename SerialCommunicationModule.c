//
// Created by Devin Morgan on 5/10/2017.
//

#include <stdio.h>
#include "SerialCommunicationModule.h"
#include "HelperFiles/ChessPiece.h"

 void readPositionFromController(Coordinate* pCoordinate, GameState gameState) {
    int row, col;
    scanf("%d%d", &row, &col);
    pCoordinate->row = row;
    pCoordinate->col = col;
}

int scanForGamePlayMode() {
    int mode;
    scanf("%d", &mode);
    return mode;
}