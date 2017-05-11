//
// Created by Devin Morgan on 5/10/2017.
//

#include <windef.h>
#include <rpcndr.h>
#include "GameStateModule.h"
#include "DisplayModule.h"
#include "SerialCommunicationModule.h"
#include "ChessGameComponents/ChessBoard.h"

// ------------------Private Functions---------------------------

bool checkIfCurrentPlayerIsInCheck(GameState* pGameState) {
    Color teamColor = pGameState->isWhitesMove ? WHITE : BLACK;
    bool foundCheck = false;

    // Find the row and col of the current player's king
    int kingRow = -1, kingCol = -1;
    bool foundKing = false;
    for (int i = 0; i < 8 && !foundKing; i++) {
        for (int j = 0; j < 8; j++) {
            ChessPiece piece = pGameState->grid[i][j];
            if (piece.type == KING && piece.color == teamColor) {
                kingRow = i; kingCol = j;
                foundKing = true;
                break;
            }
        }
    }

    // look for checks caused by rooks, bishops, and queen
    ChessPiece* left = getClosestPieceLeft(kingRow, kingCol, pGameState->grid);
    if (left != NULL
        && left->color != teamColor
        && (left->type == ROOK || left->type == QUEEN))
        return true;

    ChessPiece* upperLeft = getClosestPieceUpperLeft(kingRow, kingCol, pGameState->grid);
    if (upperLeft != NULL
        && upperLeft->color != teamColor
        && (upperLeft->type == BISHOP || upperLeft->type == QUEEN))
        return true;

    ChessPiece* upper = getClosestPieceUpper(kingRow, kingCol, pGameState->grid);
    if (upper != NULL
        && upper->color != teamColor
        && (upper->type == ROOK || upper->type == QUEEN))
        return true;

    ChessPiece* upperRight = getClosestPieceUpperRight(kingRow, kingCol, pGameState->grid);
    if (upperRight != NULL
        && upperRight->color != teamColor
        && (upperRight->type == BISHOP || upperRight->type == QUEEN))
        return true;

    ChessPiece* right = getClosestPieceRight(kingRow, kingCol, pGameState->grid);
    if (right != NULL
        && right->color != teamColor
        && (right->type == ROOK || right->type == QUEEN))
        return true;

    ChessPiece* lowerRight = getClosestPieceLowerRight(kingRow, kingCol, pGameState->grid);
    if (lowerRight != NULL
        && lowerRight->color != teamColor
        && (lowerRight->type == BISHOP || lowerRight->type == QUEEN))
        return true;

    ChessPiece* lower = getClosestPieceLower(kingRow, kingCol, pGameState->grid);
    if (lower != NULL
        && lower->color != teamColor
        && (lower->type == ROOK || lower->type == QUEEN))
        return true;

    ChessPiece* lowerLeft = getClosestPieceLowerLeft(kingRow, kingCol, pGameState->grid);
    if (lowerLeft != NULL
        && lowerLeft->color != teamColor
        && (lowerLeft->type == BISHOP || lowerLeft->type == QUEEN))
        return true;

    // look for checks caused by knights
    typedef struct {
        int x;
        int y;
    } Coordinate;

    Coordinate knightSpots[8] = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,2},{-2,1}};
    for (int i = 0; i < 8; i++) {
        Coordinate coordinate = knightSpots[i];
        int newCol = kingCol + coordinate.x;
        int newRow = kingRow + coordinate.y;

        // its a valid board position
        if (0 < newCol && newCol < 8 && 0 < newRow && newRow < 8) {
            ChessPiece piece = pGameState->grid[newRow][newCol];

            // if its an enemy knight
            if (piece.color != teamColor && piece.type == KNIGHT)
                return true;
        }
    }

    // look for checks caused by pawns
    Coordinate pawnSpots[2] = {{-1,1},{1,1}};
    for (int i = 0; i < 8; i++) {
        Coordinate coordinate = pawnSpots[i];
        int newCol = kingCol + coordinate.x;
        int newRow = kingRow + coordinate.y;

        // its a valid board position
        if (0 < newCol && newCol < 8 && 0 < newRow && newRow < 8) {
            ChessPiece piece = pGameState->grid[newRow][newCol];

            // if its an enemy pawn
            if (piece.color != teamColor && piece.type == PAWN)
                return true;
        }
    }
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
    drawUpdatedBoard(pGameState);
    pGameState->isWhitesMove = !pGameState->isWhitesMove;
}

