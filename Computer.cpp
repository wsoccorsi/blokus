//
// Created by William  Soccorsi on 12/2/18.
//

#include <iostream>
#include "Computer.h"
#include "Blokus.h"
#include <cstdlib>

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
    animatePieceMove(bestMove.piece, bestMove.position);
}

void Computer::animatePieceMove(Piece* piece, Coordinate to) {
    blokus->getEventListener().on(MainWindow::Event::ANIMATE, [=] {
        Coordinate pieceScreenPos = Coordinate(piece->getX(), piece->getY());
        Coordinate pieceCoordinate = board->screenPosToCoord(Coordinate(pieceScreenPos));
        Coordinate toScreenPos = board->coordToScreenPos(Coordinate(to.getX(), to.getY()));
        if (pieceCoordinate == to) {
            board->placePiece(piece, to);
            board->nextPlayerTurn();
            return MainWindow::POP;
        }

        Coordinate difference = Coordinate(toScreenPos.getX() - pieceScreenPos.getX(), toScreenPos.getY() - pieceScreenPos.getY());
        if (difference.getX() == 0) {
            difference.setX(1);
        }
        if (difference.getY() == 0) {
            difference.setY(1);
        }
        Coordinate offset = Coordinate(ceil(abs(difference.getX() / difference.getY())), ceil(abs(difference.getY() / difference.getX())));
        if (difference.getX() < 0) {
            offset.setX(offset.getX() * -1);
        }
        if (difference.getY() < 0) {
            offset.setY(offset.getY() * -1);
        }
        Coordinate moveTo = Coordinate(offset.getX() + piece->getX(), offset.getY() + piece->getY());
        piece->moveTo(moveTo);
        MainWindow::render();
        MainWindow::update();
        return MainWindow::CONTINUE;
    });
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
