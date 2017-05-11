//
// Created by Devin Morgan on 5/10/2017.
//

#include <windef.h>
#include <rpcndr.h>
#include "GameStateModule.h"
#include "DisplayModule.h"
#include "SerialCommunicationModule.h"

// ------------------Private Functions---------------------------

void checkIfCurrentPlayerIsInCheck(GameState* pGameState) {
    // TODO: implement me!
}

void checkIfCurrentPlayerCanMove(GameState* pGameState) {
    // TODO: implement me!
}

void updateGameStateWithMove(BoardPosition* pStartPos, BoardPosition* pEndLoc, GameState* pGameState) {
    // TODO: implement me!
}

bool validBoardLocation(BoardPosition* pPosition, GameState* pGameState) {
    // TODO: implement me!
}

bool isAnAllyPiece(BoardPosition* pPosition, GameState* pGameState) {
    // TODO: implement me!
}

bool pieceCanMove(BoardPosition* pPosition, GameState* pGameState) {
    // TODO: implement me!
}

bool pieceCanReachDestination(BoardPosition* pStartPos, BoardPosition* pEndPos, GameState* pGameState) {
    // TODO: implement me!
}

bool destinationIsNotOccupiedByAnAlly(BoardPosition* pEndPos, GameState* pGameState) {
    // TODO: implement me!
}

// -------------------Public Function------------------------------

void createNewChessGameState(GameState *gameState) {
    resetChessBoard(gameState->grid);
    gameState->isWhitesMove = true;
    gameState->canMove = true;
    gameState->inCheck = false;
    gameState->gameOver = false;
    gameState->currentMove = NULL;
}

void makeNextMove(GameState* pGameState) {
    drawScreen(pGameState);

    checkIfCurrentPlayerIsInCheck(pGameState);
    checkIfCurrentPlayerCanMove(pGameState);

    // read the appropriate player's controller for which
    // piece to move. Keep asking for a position until the
    // player chooses a legal piece to move
    BoardPosition piecePosition;
    bool isValidPiece = false;
    while (!isValidPiece) {
        promptPlayerToSelectPiece(pGameState);
        readPositionFromController(pGameState, &piecePosition);
        isValidPiece = validBoardLocation(&piecePosition, pGameState)
                      && isAnAllyPiece(&piecePosition, pGameState)
                      && pieceCanMove(&piecePosition, pGameState);
    }
    highlightSelectedSquare(pGameState, &piecePosition);

    // read the appropriate player's controller for where
    // to move the selected piece. Keep asking for a
    // position until the player chooses a legal position
    BoardPosition pieceDestination;
    bool isValidDestination = false;
    while (!isValidDestination) {
        promptPlayerToSelectDestination(pGameState);
        readPositionFromController(pGameState, &pieceDestination);
        isValidDestination = validBoardLocation(&piecePosition, pGameState)
                       && pieceCanReachDestination(&piecePosition, &pieceDestination, pGameState)
                       && destinationIsNotOccupiedByAnAlly(&pieceDestination, pGameState);
    }

    updateGameStateWithMove(&piecePosition, &pieceDestination, pGameState);
    pGameState->isWhitesMove = !pGameState->isWhitesMove;
}

