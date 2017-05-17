//
// Created by Devin Morgan on 5/10/2017.
//

#include <stdio.h>
#include "DisplayModule.h"
#include "HelperFiles/GameStateModuleHelperLibrary.h"

void drawBoard(GameState gameState) {
    prettyPrintChessBoard(gameState.grid);
}

void displayGamePlayModeMessage() {
    printf("Select your mode of play:\n1: Untimed Chess\n2: Timed Chess\n3: Quit\n");
}

void displaySelectPieceMessage(GameState gameState) {
    printf("Player %s, select piece to move.", gameState.teamColor == WHITE ? "White" : "Black");
}

void displaySelectDestinationMessage(GameState gameState) {
    printf("Player %s, select destination.", gameState.teamColor == WHITE ? "White" : "Black");
}
