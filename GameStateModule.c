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

void promptPlayerToSelectPiece(Coordinate* piece, GameState* pGameState) {
    // initialize coordinate with dummy values
    piece->row = -1;
    piece->col = -1;
    while (! validBoardLocation(*piece)) {
        displaySelectPieceMessage(*pGameState);
        readPositionFromController(piece, *pGameState);
    }
}

void promptPlayerToSelectDestination(Coordinate* destination, GameState* pGameState) {
    // initialize coordinate with dummy values
    destination->row = -1;
    destination->col = -1;
    while (! validBoardLocation(*destination)) {
        displaySelectDestinationMessage(*pGameState);
        readPositionFromController(destination, *pGameState);
    }
}

void makeNextMove(GameState* pGameState) {
    drawBoard(*pGameState);

    // read the appropriate player's controller for which
    // piece to move. Keep asking for a position until the
    // player chooses a legal piece to move
    Coordinate* piecePosition = (Coordinate*) malloc(sizeof(Coordinate));
    bool isValidPiece = false;
    while (! isValidPiece) {
        promptPlayerToSelectPiece(piecePosition, pGameState);
        isValidPiece = validBoardLocation(*piecePosition)
                       && isAnAllyPiece(*piecePosition, *pGameState);
    }

    // check if the user wanted to quit the game
    if (pGameState->gameOver)
        return;

    // read the appropriate player's controller for where
    // to move the selected piece. Keep asking for a
    // position until the player chooses a legal position
    Coordinate* pieceDestination = (Coordinate*) malloc(sizeof(Coordinate));
    bool isValidDestination = false;
    while (! isValidDestination) {
        promptPlayerToSelectDestination(pieceDestination, pGameState);
        isValidDestination = pieceCanLegallyMoveToDestination(*piecePosition, *pieceDestination, *pGameState);
    }

    // check if the user wanted to quit the game
    if (pGameState->gameOver)
        return;

    permanentlyUpdateGameStateWithMove(*piecePosition, *pieceDestination, pGameState);
    free(piecePosition);
    free(pieceDestination);
}

