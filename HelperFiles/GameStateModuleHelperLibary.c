//
// Created by Devin Morgan on 5/13/2017.
//

#include <stdbool.h>
#include "ChessBoard.h"
#include "../GameStateModule.h"
#include "GameStateModuleHelperLibary.h""


bool validBoardLocation(BoardPosition position) {
    return 0 < position.rowIndex && position.rowIndex < 8
           && 0 < position.colIndex && position.colIndex < 8;
}

bool isAnAllyPiece(BoardPosition position, GameState gameState) {
    ChessPiece piece = gameState.grid[position.rowIndex][position.colIndex];
    return piece.color == gameState.teamColor;
}

bool isAnEnemyPiece(BoardPosition position, GameState gameState) {
    return !isAnAllyPiece(position, gameState);
}

bool positionIsEmpty(BoardPosition position, GameState gameState) {
    ChessPiece piece = gameState.grid[position.rowIndex][position.colIndex];
    return piece.type == EMPTY;
}

bool isPieceOfType(BoardPosition position, PieceType type, GameState gameState) {
    ChessPiece piece = gameState.grid[position.rowIndex][position.colIndex];
    return piece.type == type;
}

// does not implement en passant (yet)
bool pawnIsCapableOfMovingToLocation(BoardPosition start, BoardPosition end, GameState gameState) {
    // for WHITE
    BoardPosition forwardLeft = {start.rowIndex-1, start.colIndex-1};
    BoardPosition forward = {start.rowIndex-1, start.colIndex};
    BoardPosition forwardForward = {start.rowIndex-2, start.colIndex};
    BoardPosition forwardRight = {start.rowIndex-1, start.colIndex+1};

    if (gameState.teamColor == BLACK) {
        forwardLeft = {start.rowIndex+1, start.colIndex+1};
        forward = {start.rowIndex+1, start.colIndex};
        forwardForward = {start.rowIndex+2, start.colIndex};
        forwardRight = {start.rowIndex+1, start.colIndex-1};
    }

    if (samePosition(forwardLeft, end) || samePosition(forwardRight, end))
        return isAnEnemyPiece(end, gameState);

    else if (samePosition(forward, end))
        return positionIsEmpty(end, gameState);

    else if (samePosition(forwardForward, end))
        return positionIsEmpty(forward, gameState) && positionIsEmpty(forwardForward, gameState);

    return false;
}

bool knightIsCapableOfMovingToLocation(BoardPosition start, BoardPosition end, GameState gameState) {
    Coordinate possibleMoves[8] = {{-2,-1}, {-1,-2}, {1,-2}, {2,-1}, {2,1}, {1,2}, {-1,2}, {-2,1}};
    for (int i = 0; i < 8; i++) {
        BoardPosition move = {possibleMoves[i].y + start.colIndex, possibleMoves[i].x + start.rowIndex};
        if (samePosition(move, end))
            return ! isAnAllyPiece(move, gameState);
    }
    return false;
}

bool bishopIsCapableOfMovingToLocation(BoardPosition start, BoardPosition end, GameState gameState) {
    // TODO: implement me!
}

bool rookIsCapableOfMovingToLocation(BoardPosition start, BoardPosition end, GameState gameState) {
    // TODO: implement me!
}

bool queenIsCapableOfMovintToLocation(BoardPosition start, BoardPosition end, GameState gameState) {
    // TODO: implement me!
}

bool kingIsCapableOfMovingToLocation(BoardPosition start, BoardPosition end, GameState gameState) {
    // TODO: implement me!
}

// returns true if, under the perfect conditions, the piece
// would be capable of moving to
// to that position, independent of the current gameState
// (except for pawns that can only move diagonally if there
// is an enemy or forwards twice if there
// returns false otherwise
// For pawns, bishops, rooks, queens, kings, returns false
// if the destination location occupied by an ally or if
// there are any pieces blocking the path to that destination
// returns false if there are not.
// For knights, returns false if the destination location
// occupied by an ally and returns true if thy are not

bool pieceIsCapableOfMovingToLocation(BoardPosition start, BoardPosition end, GameState gameState) {
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
            return queenIsCapableOfMovintToLocation(start, end, gameState);
        case KING:
            return kingIsCapableOfMovingToLocation(start, end, gameState);
    }
}

bool moveWouldNotPutKingInCheck(BoardPosition start, BoardPosition end, GameState gameState) {
    // TODO: implement me!
}