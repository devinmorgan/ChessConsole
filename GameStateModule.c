//
// Created by Devin Morgan on 5/10/2017.
//

#include <windef.h>
#include <malloc.h>
#include "GameStateModule.h"
#include "DisplayModule.h"
#include "SerialCommunicationModule.h"
#include "HelperFiles/GameStateModuleHelperLibrary.h"

PlayMode promptUserForGamePlayMode() {
    // TODO: implement me!
}

void playTimedChess() {
    // TODO: implement me!
}

void playUntimedChess() {
    // create the new untimed chess game. NOTE: this
    // will allocate memory from the Heap
    GameState* pGameState = initializeUntimedChessGame();

    // have the players alternate turns until
    // somebody wins
    while (! pGameState->gameOver)
        makeNextMove(pGameState);

    // free the Heap memory when you're done
    free(pGameState);
}

GameState* initializeUntimedChessGame() {
    GameState* pGameState = (GameState *) malloc(sizeof(GameState));
    initializeChessBoard(pGameState->grid);
    pGameState->teamColor = WHITE;
    pGameState->canMove = true;
    pGameState->inCheck = false;
    pGameState->gameOver = false;
}

void promptPlayerToSelectPiece(GameState pGameState) {
    // TODO: implement me!
}

void promptPlayerToSelectDestination(GameState* pGameState) {
    // TODO: implement me!
}

void highlightSelectedSquare(GameState* pGameState, BoardPosition* pPosition) {
    // TODO: implement me!
}

void indicateAllLegalMovesForPiece(BoardPosition position, GameState gameState) {
    // TODO: implement me!
}

bool playerIsInCheckMate(GameState gameState) {
    return currentPlayerIsInCheck(gameState) && currentPlayerHasNoLegalMoves(gameState);
}

bool currentPlayerHasNoLegalMoves(GameState gameState) {
    // TODO: implement me!
}

void makeNextMove(GameState* pGameState) {
    if (playerIsInCheckMate(*pGameState)) {
        pGameState->gameOver = true;
        return;
    }

    // read the appropriate player's controller for which
    // piece to move. Keep asking for a position until the
    // player chooses a legal piece to move
    BoardPosition piecePosition;
    bool isValidPiece = false;
    while (! isValidPiece) {
        promptPlayerToSelectPiece(*pGameState);
        readPositionFromController(pGameState, &piecePosition);
        isValidPiece = validBoardLocation(piecePosition)
                       && isAnAllyPiece(piecePosition, *pGameState);
    }
    highlightSelectedSquare(pGameState, &piecePosition);
    indicateAllLegalMovesForPiece(piecePosition, *pGameState);

    // read the appropriate player's controller for where
    // to move the selected piece. Keep asking for a
    // position until the player chooses a legal position
    BoardPosition pieceDestination;
    bool isValidDestination = false;
    while (! isValidDestination) {
        promptPlayerToSelectDestination(pGameState);
        readPositionFromController(pGameState, &pieceDestination);
        isValidDestination = pieceCanLegallyMoveToDestination(piecePosition, pieceDestination, *pGameState);
    }

    permanentlyUpdateGameStateWithMove(piecePosition, pieceDestination, pGameState);
    drawBoard(*pGameState);
}

