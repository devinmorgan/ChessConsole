#include <stdio.h>
#include <stdbool.h>
#include "GameStateModule.h"
#include "DisplayModule.h"


int main() {
    // create a new GameState
    GameState gameState;
    createNewChessGameState(&gameState);

    // draw the game on the screen
    drawScreen(*gameState);

    // each players will alternate taking
    // turns until the game ends
    while (!gameState.gameOver)
        makeNextMove(&gameState);

    return 0;
}