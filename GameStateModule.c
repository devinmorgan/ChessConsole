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
#include "HelperFiles/ChessBoard.h"

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
    // Do nothing...
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

void makeNextMove(GameState* pGameState) {
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

