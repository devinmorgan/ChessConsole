//
// Created by Devin Morgan on 5/10/2017.
//

#include "DisplayModule.h"

void drawScreen(GameState* gameState) {
    // TODO: implement me!
}

void promptPlayerToSelectPiece(GameState* pGameState) {
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

    ChessPiece piece = gameState.grid[start.rowIndex][start.colIndex];
    switch (piece.type) {
        case PAWN:
            return pawnIsCapableOfMovingToLocation(start, end, gameState);
        case KNIGHT:
            return knightIsCapableOfMovingToLocation(start, end, gameState);
        case BISHOP:
            return bishopIsCapableOfMovingToLocation(start, end, gameState);
        case ROOK:
            return rookIsCapableOfMovingToLocation(start, end, gameState);
        case QUEEN:
            return queenIsCapableOfMovingToLocation(start, end, gameState);
        case KING:
            return kingIsCapableOfMovingToLocation(start, end, gameState);
    }
}

void drawUpdatedBoard(GameState gameState) {
    // TODO: implement me!
}