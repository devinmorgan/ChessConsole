//
// Created by Devin Morgan on 5/10/2017.
//

#include <windef.h>
#include <rpcndr.h>
#include "GameStateModule.h"
#include "DisplayModule.h"
#include "SerialCommunicationModule.h"
#include "GameStateModuleHelperLibary.h"

// ------------------Private Functions---------------------------

bool checkIfCurrentPlayerIsInCheck(GameState gameState) {
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

bool pieceCanLegallyMoveToDestination(BoardPosition start, BoardPosition end, GameState gameState) {
    return validBoardLocation(end)
           && pieceIsCapableOfMovingToLocation(start, end, gameState)
           && moveWouldNotPutKingInCheck(start, end, gameState);
}

void updateGameStateWithMove(BoardPosition* pStartPos, BoardPosition* pEndLoc, GameState* pGameState) {
    // TODO: implement me!
}

// -------------------Public Function------------------------------

void createNewChessGameState(GameState *gameState) {
    resetChessBoard(gameState->grid);
    gameState->teamColor = WHITE;
    gameState->canMove = true;
    gameState->inCheck = false;
    gameState->gameOver = false;
    gameState->currentMove = NULL;
}

void makeNextMove(GameState* pGameState) {
    checkIfCurrentPlayerIsInCheck(*pGameState);

    // read the appropriate player's controller for which
    // piece to move. Keep asking for a position until the
    // player chooses a legal piece to move
    BoardPosition piecePosition;
    bool isValidPiece = false;
    while (!isValidPiece) {
        promptPlayerToSelectPiece(pGameState);
        readPositionFromController(pGameState, &piecePosition);
        isValidPiece = validBoardLocation(piecePosition)
                       && isAnAllyPiece(piecePosition, *pGameState);
    }
    highlightSelectedSquare(pGameState, &piecePosition);
    indicateAllLegalMovesForPiece(piecePosition, pGameState);

    // read the appropriate player's controller for where
    // to move the selected piece. Keep asking for a
    // position until the player chooses a legal position
    BoardPosition pieceDestination;
    bool isValidDestination = false;
    while (!isValidDestination) {
        promptPlayerToSelectDestination(pGameState);
        readPositionFromController(pGameState, &pieceDestination);
        isValidDestination = pieceCanLegallyMoveToDestination(piecePosition, pieceDestination, *pGameState);
    }

    updateGameStateWithMove(&piecePosition, &pieceDestination, pGameState);
    drawUpdatedBoard(pGameState);
    pGameState->teamColor = pGameState->teamColor == WHITE ? BLACK : WHITE;
}

