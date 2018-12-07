#include <iostream>
#include "Board.h"
#include "Blokus.h"
#include <iostream>
#include "Player.h"
using namespace std;

/**
 *
 */
Board::Board() {
    this->blokus = nullptr;
}

/**
 * Creates the board
 *
 * @param blokus
 * @param x
 * @param y
 */
Board::Board(Blokus* blokus, int x, int y): TileGrid(x, y, 20, 20) {
    this->blokus = blokus;

    for (std::vector<Tile*> tileColumn: tiles) {
        for (Tile* tile : tileColumn) {
            MainWindow* mainWindow = (MainWindow*) this->blokus;
            mainWindow->addClickable(tile);
            tile->setOnClick([=] (Coordinate coord) {
                if (this->blokus->clickedPiece != nullptr) {
                    Coordinate pieceCoord = screenPosToCoord(coord);
                    if (isValidMove(this->blokus->clickedPiece, pieceCoord)) {
                        placePiece(this->blokus->clickedPiece, pieceCoord);
                        this->blokus->clickedPiece = nullptr;
                        blokus->nextPlayerTurn();
                    }
                }
            });
        }
    }
}



/**
 *
 * @param piece
 * @param coord
 * @return
 */
bool Board::doesBorderOwnEdge(Piece *piece, Coordinate coord) {
    std::vector<Coordinate> pieceCoords;
    return false;
}

/**
 *
 * @param piece
 * @param coord
 * @return
 */
bool Board::cornersDoTouch(Piece *piece, Coordinate coord) {
    return false;
}
/**
 *
 * @param piece
 * @param coord
 * @return
 */
bool Board::isValidMove(Piece* piece, Coordinate coord) {
    if (!pieceIsWithinBounds(piece, coord)) {
        return false;
    }
    if (pieceOverlaps(piece, coord)) {
        return false;
    }

    Coordinate start = piece->getPlayer()->getStart();
    if (pieceGrid[start.getX()][start.getY()] == nullptr) {
        for (Coordinate formCoord : piece->getForm()) {
            Coordinate position = coord + formCoord;
            if (position == start) {
                return true;
            }
        }
    }


    // check edges for my own pieces
    for (Coordinate edge : std::vector<Coordinate> {
            Coordinate(0, 1),
            Coordinate(0, -1),
            Coordinate(1, 0),
            Coordinate(-1, 0)
    }) {
        for (Coordinate formCord : piece->getForm()) {
            Coordinate borderingPosition = coord + formCord + edge;
            if (borderingPosition.getX() < xTiles && borderingPosition.getX() >= 0 &&
                borderingPosition.getY() < yTiles && borderingPosition.getY() >= 0) {
                Piece* borderingPiece = pieceGrid[borderingPosition.getX()][borderingPosition.getY()];
                if (borderingPiece != nullptr) {
                    if (borderingPiece->getPlayer() == piece->getPlayer()) {
                        return false;
                    }
                }
            }
        }
    }

    // check corners for my own pieces
    bool atLeastOneCornerIsMyOwn = false;
    for (Coordinate corner : piece->getCornerForm()) {
        Coordinate cornerPosition = coord + corner;
        if (cornerPosition.getX() < xTiles && cornerPosition.getX() >= 0 &&
            cornerPosition.getY() < yTiles && cornerPosition.getY() >= 0) {
            Piece* cornerPiece = pieceGrid[cornerPosition.getX()][cornerPosition.getY()];
            if (cornerPiece != nullptr) {
                if (cornerPiece->getPlayer() == piece->getPlayer()) {
                    atLeastOneCornerIsMyOwn = true;
                    break;
                }
            }
        }
    }
    if (!atLeastOneCornerIsMyOwn) {
        return false;
    }


    return true;
}

void Board::nextPlayerTurn() {
    blokus->nextPlayerTurn();
}

