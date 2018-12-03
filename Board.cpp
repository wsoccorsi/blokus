#include <iostream>
#include "Board.h"
#include "Blokus.h"


Board::Board() {
    this->blokus = nullptr;
}

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

bool Board::doesBorderOwnEdge(Piece *piece, Coordinate coord) {
    std::vector<Coordinate> pieceCoords;

    return false;
}

bool Board::cornersDoTouch(Piece *piece, Coordinate coord) {
    return false;
}

bool Board::isValidMove(Piece* piece, Coordinate coord) {
    if (!pieceIsWithinBounds(piece, coord)) {
        return false;
    }
    if (pieceOverlaps(piece, coord)) {
        return false;
    }
    return true;
}
