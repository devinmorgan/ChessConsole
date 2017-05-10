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

    promptPlayerToSelectPiece(gameState->isWhitesMove);

    // read the appropriate player's controller for which
    // piece to move. Keep asking for a position until the
    // player chooses a legal piece to move
    BoardPosition selectedFromPosition;
    do {
        readPositionFromController(&selectedFromPosition, gameState->isWhitesMove);
    } while (! isValidPieceToMove(selectedFromPosition, gameState->isWhitesMove));

    // get the legal moves for the selected piece
    BoardPosition legalMoves[] = {{-1,-1}};
    getLegalMovesForPiece(selectedFromPosition, &legalMoves);

    promptPlayerToSelectEndLocation(gameState->isWhitesMove);

    // read the appropriate player's controller for where
    // to move the selected piece. Keep asking for a position
    // until the player chooses a legal position for the piece
    BoardPosition selectedToPosition;
    do {
        readPositionFromController(&selectedToPosition, gameState->isWhitesMove);
    } while (! isLegalEndLocation(selectedToPosition, legalMoves, gameState->isWhitesMove));

    // update the board with the valid move and re-draw it on
    // the screen
    updateChessBoardWithMove(selectedFromPosition, selectedToPosition, *gameState);
    gameState->isCheck = checkOtherPlayerForCheck(gameState);
    drawBoard(gameState);



    // now its the other players turn
    gameState->isWhitesMove = ! gameState->isWhitesMove;
}