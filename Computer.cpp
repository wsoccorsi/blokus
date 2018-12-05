//
// Created by William  Soccorsi on 12/2/18.
//

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

}

std::vector<Computer::PossibleMove> Computer::getPossibleMoves() {
    std::vector<Computer::PossibleMove> possibleMoves = std::vector<Computer::PossibleMove>();
    for (int x = 0; x < board->getXTiles(); x++) {
        for (int y = 0; y < board->getYTiles(); y++) {
            Coordinate position = Coordinate(x, y);
            for (Piece* piece : tray->getPieces()) {
                std::vector<Coordinate> form = piece->getForm();
                for (int i = 0; i < 3; i++) {
                    Piece* testPiece = new Piece(blokus, );
                }
            }
        }
    }

    return possibleMoves;
}
