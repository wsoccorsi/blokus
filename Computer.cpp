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
Computer::Computer(Blokus* blokus, Color color, std::string title, Coordinate trayCoord, Board* board) : Player(blokus, color, title, trayCoord) {
    this->board = board;
}

void Computer::takeTurn() {
    PossibleMove bestMove = getBestMove();
    for (int i = 0; i < bestMove.rotation; i++) {
        bestMove.piece->rotateRight();
    }
    tray->removePiece(bestMove.piece);
    board->placePiece(bestMove.piece, bestMove.position);
    board->nextPlayerTurn();
}

void Computer::animatePieceMove() {

    //glutTimerFunc(30, [=]{return 0;}, 0);
}

Computer::PossibleMove Computer::getBestMove() {
    PossibleMove bestMove = PossibleMove();
    for (PossibleMove possibleMove : getPossibleMoves()) {
        possibleMove.score = getMoveHeuristic(possibleMove);
        if (possibleMove.score > bestMove.score) {
            bestMove = possibleMove;
        }
    }
    return bestMove;
}

int Computer::getMoveHeuristic(Computer::PossibleMove possibleMove) {
    int heuristic = 0;
    heuristic += possibleMove.piece->getTiles().size();
    return heuristic;
}

std::vector<Computer::PossibleMove> Computer::getPossibleMoves() {
    std::vector<Computer::PossibleMove> possibleMoves = std::vector<Computer::PossibleMove>();
    for (int x = 0; x < board->getXTiles(); x++) {
        for (int y = 0; y < board->getYTiles(); y++) {
            Coordinate position = Coordinate(x, y);
            for (Piece* piece : tray->getPieces()) {
                std::vector<Coordinate> form = piece->getForm();
                for (int i = 0; i < 3; i++) {
                    Piece* testPiece = new Piece(blokus, form, piece->getPlayer(), 0, 0);
                    for (int rotationCount = 0; rotationCount < i; rotationCount++) {
                        testPiece->rotateRight();
                    }
                    if (board->isValidMove(testPiece, position)) {
                        possibleMoves.push_back(PossibleMove(piece, position, i));
                    }
                }
            }
        }
    }

    return possibleMoves;
}
