//
// Created by Devin Morgan on 5/10/2017.
//

#include "GameStateModule.h"

#ifndef CHESSCONSOLE_DRAWSCREEN_H
#define CHESSCONSOLE_DRAWSCREEN_H

void drawScreen(GameState* gameState);

void promptPlayerToSelectPiece(GameState* pGameState);

void promptPlayerToSelectDestination(GameState* pGameState);

void highlightSelectedSquare(GameState* pGameState, BoardPosition* pPosition);

#endif //CHESSCONSOLE_DRAWSCREEN_H