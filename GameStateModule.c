//
// Created by Devin Morgan on 5/10/2017.
//

#include <windef.h>
#include "GameStateModule.h"
#include "DisplayModule.h"
#include "SerialCommunicationModule.h"

void createNewChessGameState(GameState *gameState) {
    resetChessBoard(gameState->grid);
    gameState->teamColor = WHITE;
    gameState->canMove = true;
    gameState->inCheck = false;
    gameState->gameOver = false;
    gameState->currentMove = NULL;
}

void makeNextMove(GameState* pGameState) {
    currentPlayerIsInCheck(*pGameState);

    // read the appropriate player's controller for which
    // piece to move. Keep asking for a position until the
    // player chooses a legal piece to move
    BoardPosition piecePosition;
    bool isValidPiece = false;
    while (!isValidPiece) {
        promptPlayerToSelectPiece(pGameState);
        readPositionFromController(pGameState, &piecePosition);
        isValidPiece = validBoardLocation(piecePosition)
                       && isAnAllyPiece(piecePosition, *pGameState);
    }
    highlightSelectedSquare(pGameState, &piecePosition);
    indicateAllLegalMovesForPiece(piecePosition, pGameState);

    // read the appropriate player's controller for where
    // to move the selected piece. Keep asking for a
    // position until the player chooses a legal position
    BoardPosition pieceDestination;
    bool isValidDestination = false;
    while (!isValidDestination) {
        promptPlayerToSelectDestination(pGameState);
        readPositionFromController(pGameState, &pieceDestination);
        isValidDestination = pieceCanLegallyMoveToDestination(piecePosition, pieceDestination, *pGameState);
    }

    permanentlyUpdateGameStateWithMove(&piecePosition, &pieceDestination, pGameState);
    drawUpdatedBoard(pGameState);
}

