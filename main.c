#include <stdio.h>
#include <stdbool.h>
#include "ChessGameState.h"



int main() {
    // create a new ChessGameState
    ChessGameState gameState;
    createNewChessGameState(&gameState);

    // each players will alternate taking
    // turns until the game ends
    while (!gameState.gameOver)
        makeNextMove(&gameState);

    return 0;
}