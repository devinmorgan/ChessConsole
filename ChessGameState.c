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
    promptPlayerForWhichPieceToMove(gameState->isWhitesMove);

    // read the appropriate player's controller for which
    // piece to move. Keep asking for a position until the
    // player chooses a legal piece to move
    BoardPosition selectedFromPosition;
    do {
        readPositionFromController(&selectedFromPosition, gameState->isWhitesMove);
    } while (! isValidFromPosition(selectedFromPosition, gameState->isWhitesMove));

    // get the legal moves for the selected piece
    BoardPosition legalMoves[] = {{-1,-1}};
    getLegalMovesForPieceAtPosition(selectedFromPosition, &legalMoves);

    promptPlayerForWhereToMovePiece(gameState->isWhitesMove);

    // read the appropriate player's controller for where
    // to move the selected piece. Keep asking for a position
    // until the player chooses a legal position for the piece
    BoardPosition selectedToPosition;
    do {
        readPositionFromController(&selectedToPosition, gameState->isWhitesMove);
    } while (! isLegalToPosition(selectedToPosition, legalMoves, gameState->isWhitesMove));


    updateChessBoardWithMove(selectedFromPosition, selectedToPosition, *gameState);
    gameState->isWhitesMove = ! gameState->isWhitesMove;
}