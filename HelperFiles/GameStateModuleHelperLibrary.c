//
// Created by Devin Morgan on 5/13/2017.
//

#include <stdbool.h>
#include <windef.h>
#include "ChessBoard.h"
#include "GameStateModuleHelperLibrary.h""


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

// ------------helpers for pieceIsCapableOfMovingToLocation()----------------------
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

// TODO: implement en passant for pawns
bool pawnIsCapableOfMovingToLocation(BoardPosition start, BoardPosition end, GameState gameState) {
    // NOTE this is NOT symmetric for black and WHITE

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
    // NOTE: this is symmetric for both BLACK and WHITE
    Coordinate possibleMoves[8] = {{-2,-1}, {-1,-2}, {1,-2}, {2,-1}, {2,1}, {1,2}, {-1,2}, {-2,1}};
    for (int i = 0; i < 8; i++) {
        BoardPosition move = {possibleMoves[i].y + start.rowIndex, possibleMoves[i].x + start.colIndex};
        if (samePosition(move, end))
            return ! isAnAllyPiece(move, gameState);
    }
    return false;
}

bool bishopIsCapableOfMovingToLocation(BoardPosition start, BoardPosition end, GameState gameState) {
    // NOTE: this is symmetric for both BLACK and WHITE

    bool forwardLeftIsNotObstructed = true;
    bool forwardRightIsNotObstructed = true;
    bool backwardLeftIsNotObstructed = true;
    bool backwardRightIsNotObstructed = true;

    for (int i = 1; i <= 7; i++) {
        BoardPosition forwardLeft = {start.rowIndex -i, start.colIndex -i};
        BoardPosition forwardRight = {start.rowIndex +i, start.colIndex -i};
        BoardPosition backwardRight = {start.rowIndex +i, start.colIndex +i};
        BoardPosition backwardLeft = {start.rowIndex -i, start.colIndex +i};

        // search forwardLeft, forwardRight, backwardRight, and backwardLeft
        // direction for the desired position to determine if the bishop can
        // move there by checking if path is obstructed on the way there or
        // if there is an ally already at the desired spot

        if (forwardLeftIsNotObstructed) {
            if (samePosition(forwardLeft, end)
                && (isAnEnemyPiece(forwardLeft, gameState) || positionIsEmpty(forwardLeft, gameState)))
                    return true;
            if (! (validBoardLocation(forwardLeft) && positionIsEmpty(forwardLeft, gameState)))
                forwardLeftIsNotObstructed = false;
        }

        if (forwardRightIsNotObstructed) {
            if (samePosition(forwardRight, end)
                && (isAnEnemyPiece(forwardRight, gameState) || positionIsEmpty(forwardRight, gameState)))
                return true;
            if (! (validBoardLocation(forwardRight) && positionIsEmpty(forwardRight, gameState)))
                forwardRightIsNotObstructed = false;
        }

        if (backwardRightIsNotObstructed) {
            if (samePosition(backwardRight, end)
                && (isAnEnemyPiece(backwardRight, gameState) || positionIsEmpty(backwardRight, gameState)))
                return true;
            if (! (validBoardLocation(backwardRight) && positionIsEmpty(backwardRight, gameState)))
                backwardRightIsNotObstructed = false;
        }

        if (backwardLeftIsNotObstructed) {
            if (samePosition(backwardLeft, end)
                && (isAnEnemyPiece(backwardLeft, gameState) || positionIsEmpty(backwardLeft, gameState)))
                return true;
            if (! (validBoardLocation(backwardLeft) && positionIsEmpty(backwardLeft, gameState)))
                backwardLeftIsNotObstructed = false;
        }
    }

    return false;
}

bool rookIsCapableOfMovingToLocation(BoardPosition start, BoardPosition end, GameState gameState) {
    // NOTE: this is symmetric for both BLACK and WHITE

    bool leftIsNotObstructed = true;
    bool forwardIsNotObstructed = true;
    bool rightIsNotObstructed = true;
    bool backwardIsNotObstructed = true;

    for (int i = 1; i <= 7; i++) {
        BoardPosition left = {start.rowIndex, start.colIndex -i};
        BoardPosition forward = {start.rowIndex -i, start.colIndex};
        BoardPosition right = {start.rowIndex, start.colIndex +i};
        BoardPosition backward = {start.rowIndex +i, start.colIndex};

        // search the left, forward, right, and backward directions
        // for the desired position to determine if the rook can move
        // there by checking if path is obstructed on the way there or
        // if there is an ally already at the desired spot

        if (leftIsNotObstructed) {
            if (samePosition(left, end)
                && (isAnEnemyPiece(left, gameState) || positionIsEmpty(left, gameState)))
                return true;
            if (! (validBoardLocation(left) && positionIsEmpty(left, gameState)))
                leftIsNotObstructed = false;
        }

        if (forwardIsNotObstructed) {
            if (samePosition(forward, end)
                && (isAnEnemyPiece(forward, gameState) || positionIsEmpty(forward, gameState)))
                return true;
            if (! (validBoardLocation(forward) && positionIsEmpty(forward, gameState)))
                forwardIsNotObstructed = false;
        }

        if (rightIsNotObstructed) {
            if (samePosition(right, end)
                && (isAnEnemyPiece(right, gameState) || positionIsEmpty(right, gameState)))
                return true;
            if (! (validBoardLocation(right) && positionIsEmpty(right, gameState)))
                rightIsNotObstructed = false;
        }

        if (backwardIsNotObstructed) {
            if (samePosition(backward, end)
                && (isAnEnemyPiece(backward, gameState) || positionIsEmpty(backward, gameState)))
                return true;
            if (! (validBoardLocation(backward) && positionIsEmpty(backward, gameState)))
                backwardIsNotObstructed = false;
        }
    }

    return false;
}

bool queenIsCapableOfMovingToLocation(BoardPosition start, BoardPosition end, GameState gameState) {
    return bishopIsCapableOfMovingToLocation(start, end, gameState)
           || rookIsCapableOfMovingToLocation(start, end, gameState);
}

// TODO: implement castling for king
bool kingIsCapableOfMovingToLocation(BoardPosition start, BoardPosition end, GameState gameState) {
    // NOTE: this is symmetric for both BLACK and WHITE
    Coordinate possibleMoves[8] = {{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};
    for (int i = 0; i < 8; i++) {
        BoardPosition move = {start.rowIndex + possibleMoves[i].y, start.colIndex + possibleMoves[i].x};

        if (samePosition(move, end))
            return isAnEnemyPiece(move, gameState) || positionIsEmpty(move, gameState);
    }

    return false;
}

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
            return queenIsCapableOfMovingToLocation(start, end, gameState);
        case KING:
            return kingIsCapableOfMovingToLocation(start, end, gameState);
    }
}

// ------------helpers for moveWouldPutSelfInCheck()----------------------
bool currentPlayerIsInCheck(GameState gameState) {
    // Find the row and col of the current player's king
    int kingRow = -1, kingCol = -1;
    bool foundKing = false;
    for (int i = 0; i < 8 && !foundKing; i++) {
        for (int j = 0; j < 8; j++) {
            ChessPiece piece = gameState.grid[i][j];
            if (piece.type == KING && piece.color == gameState.teamColor) {
                kingRow = i; kingCol = j;
                foundKing = true;
                break;
            }
        }
    }

    // look for checks caused by rooks, bishops, and queen
    ChessPiece* left = getClosestPieceLeft(kingRow, kingCol, gameState.grid);
    if (left != NULL
        && left->color != gameState.teamColor
        && (left->type == ROOK || left->type == QUEEN))
        return true;

    ChessPiece* upperLeft = getClosestPieceUpperLeft(kingRow, kingCol, gameState.grid);
    if (upperLeft != NULL
        && upperLeft->color != gameState.teamColor
        && (upperLeft->type == BISHOP || upperLeft->type == QUEEN))
        return true;

    ChessPiece* upper = getClosestPieceUpper(kingRow, kingCol, gameState.grid);
    if (upper != NULL
        && upper->color != gameState.teamColor
        && (upper->type == ROOK || upper->type == QUEEN))
        return true;

    ChessPiece* upperRight = getClosestPieceUpperRight(kingRow, kingCol, gameState.grid);
    if (upperRight != NULL
        && upperRight->color != gameState.teamColor
        && (upperRight->type == BISHOP || upperRight->type == QUEEN))
        return true;

    ChessPiece* right = getClosestPieceRight(kingRow, kingCol, gameState.grid);
    if (right != NULL
        && right->color != gameState.teamColor
        && (right->type == ROOK || right->type == QUEEN))
        return true;

    ChessPiece* lowerRight = getClosestPieceLowerRight(kingRow, kingCol, gameState.grid);
    if (lowerRight != NULL
        && lowerRight->color != gameState.teamColor
        && (lowerRight->type == BISHOP || lowerRight->type == QUEEN))
        return true;

    ChessPiece* lower = getClosestPieceLower(kingRow, kingCol, gameState.grid);
    if (lower != NULL
        && lower->color != gameState.teamColor
        && (lower->type == ROOK || lower->type == QUEEN))
        return true;

    ChessPiece* lowerLeft = getClosestPieceLowerLeft(kingRow, kingCol, gameState.grid);
    if (lowerLeft != NULL
        && lowerLeft->color != gameState.teamColor
        && (lowerLeft->type == BISHOP || lowerLeft->type == QUEEN))
        return true;

    // look for checks caused by knights
    Coordinate knightSpots[8] = {{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
    for (int i = 0; i < 8; i++) {
        BoardPosition position = {kingCol + knightSpots[i].x, kingRow + knightSpots[i].y};

        if (validBoardLocation(position)
            && isAnEnemyPiece(position, gameState)
            && isPieceOfType(position, KNIGHT, gameState))
            return true;
    }

    // look for checks caused by pawns
    BoardPosition diagLeft = {kingRow-1, kingCol-1};
    BoardPosition diagRight = {kingRow-1, kingCol+1};

    // adjust the column indices if black instead of white
    if (gameState.teamColor == BLACK) {
        diagLeft.rowIndex += 2;
        diagRight.rowIndex += 2;
    }

    if (validBoardLocation(diagLeft)
        && isAnEnemyPiece(diagLeft, gameState)
        && isPieceOfType(diagRight, PAWN, gameState))
        return true;

    if (validBoardLocation(diagRight)
        && isAnEnemyPiece(diagRight, gameState)
        && isPieceOfType(diagRight, PAWN, gameState))
        return true;

    // didn't find a check
    return false;
}

bool moveWouldPutSelfInCheck(BoardPosition start, BoardPosition end, GameState gameState) {
    // move the piece from the start position to the end position
    ChessPiece pieceToMove = gameState.grid[start.rowIndex][start.colIndex];
    gameState.grid[end.rowIndex][end.colIndex] = pieceToMove;

    // return whether the current player would be in check or not
    return currentPlayerIsInCheck(gameState);
}

bool pieceCanLegallyMoveToDestination(BoardPosition start, BoardPosition end, GameState gameState) {
    return validBoardLocation(end)
           && pieceIsCapableOfMovingToLocation(start, end, gameState)
           && !moveWouldPutSelfInCheck(start, end, gameState);
}

void permanentlyUpdateGameStateWithMove(BoardPosition start, BoardPosition end, GameState *pGameState) {
    // move the piece from the start position to the end position
    ChessPiece* pPieceToMove = &(pGameState->grid[start.rowIndex][start.colIndex]);
    pGameState->grid[end.rowIndex][end.colIndex] = *pPieceToMove;

    // indicate that the piece has now moved at least once
    pPieceToMove->hasMoved = true;

    // switch the players turn by change the teamColor variable
    pGameState->teamColor = pGameState->teamColor == WHITE ? BLACK : WHITE;
}