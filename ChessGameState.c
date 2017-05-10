//
// Created by Devin Morgan on 5/10/2017.
//

#include "ChessGameState.h"

void createNewChessGameState(ChessGameState *gameState) {
    resetChessBoard(gameState->grid);
    gameState->gameOver = false;
    gameState->isWhitesMove = true;
}

void makeNextMove(ChessGameState *gameState) {
    drawGameScreen(*gameState);
    checkIfCurrentPlayerIsInCheck(*gameState);
    checkIfCurrentPlayerCanMove(*gameState);

    // read the appropriate player's controller for which
    // piece to move. Keep asking for a position until the
    // player chooses a legal piece to move
    BoardPosition selectedFromPosition;
    bool isValidPiece = false;
    do {
        promptPlayerToSelectPiece(gameState->isWhitesMove);
        readPositionFromController(&selectedFromPosition, gameState->isWhitesMove);
        isValidPiece = validBoardLocation(selectedFromPosition)
                      && isCurrentPlayersPiece(selectedFromPosition, gameState->isWhitesMove)
                      && pieceCanMove(selectedFromPosition);
    } while (!isValidPiece);

    highlightSelectedSquare(selectedFromPosition);

    // read the appropriate player's controller for where
    // to move the selected piece. Keep asking for a
    // position until the player chooses a legal position
    BoardPosition selectedToPosition;
    bool isValidDestination = false;
    do {
        promptPlayerToSelectLocation(gameState->isWhitesMove);
        readPositionFromController(&selectedToPosition, gameState->isWhitesMove);
        isValidDestination = validBoardLocation(selectedFromPosition)
                       && pieceCanReachDestination(selectedFromPosition, selectedToPosition)
                       && destinationIsNotOccupiedByAlly(selectedFromPosition);
    } while (!isValidDestination);

    updateBoardWithMove(selectedFromPosition, selectedToPosition);
    gameState->isWhitesMove = !gameState->isWhitesMove;
}
