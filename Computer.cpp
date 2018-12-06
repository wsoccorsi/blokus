//
// Created by William  Soccorsi on 12/2/18.
//

#include <iostream>
#include "Computer.h"

/**
 *
 * @param blokus
 * @param color
 * @param title
 * @param trayCoord
 */
Computer::Computer(Blokus* blokus, Color color, Coordinate trayCoord, Board* board, Coordinate start) : Player(blokus, color, trayCoord, board, start) {
}

void Computer::takeTurn() {
    PossibleMove bestMove = getBestMove();
    tray->removePiece(bestMove.piece);
    for (int i = 0; i < bestMove.rotation; i++) {
        bestMove.piece->rotateRight();
    }
    board->placePiece(bestMove.piece, bestMove.position);
    board->nextPlayerTurn();
}

void Computer::animatePieceMove() {

    //glutTimerFunc(30, [=]{return 0;}, 0);
}

Player::PossibleMove Computer::getBestMove() {
    PossibleMove bestMove = PossibleMove();
    for (PossibleMove possibleMove : getPossibleMoves()) {
        possibleMove.score = getMoveHeuristic(possibleMove);
        if (possibleMove.score > bestMove.score) {
            bestMove = possibleMove;
        }
    }
    return bestMove;
}

int Computer::getMoveHeuristic(Player::PossibleMove possibleMove) {
    int heuristic = 0;
    heuristic += possibleMove.piece->getTiles().size();
    return heuristic;
}
