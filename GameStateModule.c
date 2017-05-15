//
// Created by Devin Morgan on 5/10/2017.
//

#include <windef.h>
#include <malloc.h>
#include "GameStateModule.h"
#include "DisplayModule.h"
#include "SerialCommunicationModule.h"
#include "HelperFiles/GameStateModuleHelperLibrary.h"
#include "HelperFiles/ChessPiece.h"

PlayMode promptUserForGamePlayMode() {
    displayGamePlayModeMessage();
    int response = scanForGamePlayMode();
    switch (response) {
        case 1:
            return UNTIMED;
        case 2:
            return TIMED;
        default:
            return EXIT;
    }
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

Coordinate promptPlayerToSelectPiece(GameState* pGameState) {
    displaySelectPieceMessage(*pGameState);
    Coordinate response = readPositionFromController(*pGameState);

    // always make sure to check if the user wants to quit the game
    if (response.row == 0 && response.col == 0)
        pGameState->gameOver = true;

    return response;

}

Coordinate promptPlayerToSelectDestination(GameState* pGameState) {
    displaySelectDestinationMessage(*pGameState);
    Coordinate response = readPositionFromController(*pGameState);

    // always make sure to check if the user wants to quit the game
    if (response.row == 0 && response.col == 0)
        pGameState->gameOver = true;

    return response;
}

void highlightSelectedSquare(GameState* pGameState, Coordinate* pPosition) {
    // TODO: implement me!
}

void indicateAllLegalMovesForPiece(Coordinate position, GameState gameState) {
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
    Coordinate piecePosition;
    bool isValidPiece = false;
    while (! isValidPiece) {
        piecePosition = promptPlayerToSelectPiece(pGameState);
        isValidPiece = validBoardLocation(piecePosition)
                       && isAnAllyPiece(piecePosition, *pGameState);
    }

    // check if the user wanted to quit the game
    if (pGameState->gameOver)
        return;

    highlightSelectedSquare(pGameState, &piecePosition);
    indicateAllLegalMovesForPiece(piecePosition, *pGameState);

    // read the appropriate player's controller for where
    // to move the selected piece. Keep asking for a
    // position until the player chooses a legal position
    Coordinate pieceDestination;
    bool isValidDestination = false;
    while (! isValidDestination) {
        pieceDestination = promptPlayerToSelectDestination(pGameState);
        isValidDestination = pieceCanLegallyMoveToDestination(piecePosition, pieceDestination, *pGameState);
    }

    // check if the user wanted to quit the game
    if (pGameState->gameOver)
        return;

    permanentlyUpdateGameStateWithMove(piecePosition, pieceDestination, pGameState);
    drawBoard(*pGameState);
}

