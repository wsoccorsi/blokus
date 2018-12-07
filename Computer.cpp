//
// Created by William  Soccorsi on 12/2/18.
//

#include <iostream>
#include "Computer.h"
#include "Blokus.h"
#include <cstdlib>

/**
 * Computer constructor
 *
 * @param blokus
 * @param color
 * @param title
 * @param trayCoord
 */
Computer::Computer(Blokus* blokus, Color color, Coordinate trayCoord, Board* board, Coordinate start, std::string title) : Player(blokus, color, trayCoord, board, start, title) {
}

/**
 * Computer take turn method to find best move as well
 *
 */
void Computer::takeTurn() {
    PossibleMove bestMove = getBestMove();
    tray->removePiece(bestMove.piece);
    for (int i = 0; i < bestMove.rotation; i++) {
        bestMove.piece->rotateRight();
    }
    animatePieceMove(bestMove.piece, bestMove.position);
}

/**
 *  to animate the piece movement
 *
 * @param piece
 * @param to
 */
void Computer::animatePieceMove(Piece* piece, Coordinate to) {
    piece->setZ(15);
    MainWindow::updateDrawables();
    blokus->getEventListener().on(MainWindow::Event::ANIMATE, [=] {
        Coordinate pieceScreenPos = Coordinate(piece->getX(), piece->getY());
        Coordinate pieceCoordinate = board->screenPosToCoord(Coordinate(pieceScreenPos));
        Coordinate toScreenPos = board->coordToScreenPos(Coordinate(to.getX(), to.getY()));
        if (pieceCoordinate == to) {
            board->placePiece(piece, to);
            piece->setZ(3);
            MainWindow::updateDrawables();
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

/**
 * getter for best move
 *
 * @return
 */
Player::PossibleMove Computer::getBestMove() {
    std::vector<PossibleMove> bestMoves = std::vector<PossibleMove>();
    for (PossibleMove possibleMove : getPossibleMoves()) {
        possibleMove.score = getMoveHeuristic(possibleMove);
        if (bestMoves.empty()) {
            bestMoves.push_back(possibleMove);
        } else if (possibleMove.score > bestMoves[0].score) {
            bestMoves.push_back(possibleMove);
        }
    }
    std::random_shuffle(bestMoves.begin(), bestMoves.end());
    return bestMoves[0];
}

/**
 * getter for move heuristic
 *
 * @param possibleMove
 * @return
 */
int Computer::getMoveHeuristic(Player::PossibleMove possibleMove) {
    int heuristic = 0;

    // strategy from:
    // http://www.ultraboardgames.com/blokus/tips.php

    // try to place bigger pieces first
    heuristic += possibleMove.piece->getTiles().size() * 2;

    // try to place pieces such that more open corners are available for the next turn
    for (Coordinate cornerFormCoord : possibleMove.cornerForm) {
        Coordinate cornerBoardPosition = possibleMove.position + cornerFormCoord;
        if (cornerBoardPosition.getX() < board->getXTiles() && cornerBoardPosition.getX() >= 0 &&
            cornerBoardPosition.getY() < board->getYTiles() && cornerBoardPosition.getY() >= 0) {
            if (board->getPieceGrid()[cornerBoardPosition.getX()][cornerBoardPosition.getY()] == nullptr) {
                bool cornerIsValidMove = true;
                for (Coordinate edge : std::vector<Coordinate> {
                        Coordinate(0, 1),
                        Coordinate(0, -1),
                        Coordinate(1, 0),
                        Coordinate(-1, 0)
                }) {
                    Coordinate edgeOfCornerPosition = cornerBoardPosition + edge;
                    if (edgeOfCornerPosition.getX() < board->getXTiles() && edgeOfCornerPosition.getX() >= 0 &&
                        edgeOfCornerPosition.getY() < board->getYTiles() && edgeOfCornerPosition.getY() >= 0) {
                        if (board->getPieceGrid()[edgeOfCornerPosition.getX()][edgeOfCornerPosition.getY()] != nullptr) {
                            if (board->getPieceGrid()[edgeOfCornerPosition.getX()][edgeOfCornerPosition.getY()]->getPlayer() == possibleMove.piece->getPlayer()) {
                                cornerIsValidMove = false;
                                break;
                            }
                        }
                    }
                }
                if (cornerIsValidMove) {
                    heuristic += 1;
                }
            }
        }
    }

    return heuristic;
}
