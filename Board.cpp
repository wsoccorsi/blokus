#include <iostream>
#include "Board.h"
#include "Blokus.h"


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

    //Check if its placeable
    for (int i = 0; i < piece->getForm().size(); ++i){
        if (pieceGrid[piece->getForm()[i].getX() + coord.getX()][piece->getForm()[i].getY() + coord.getY()] != 0

            //Check Y
            && pieceGrid[piece->getForm()[i].getX() + coord.getX()][piece->getForm()[i].getY() + coord.getY() +1] != 0
            && pieceGrid[piece->getForm()[i].getX() + coord.getX()][piece->getForm()[i].getY() + coord.getY() -1] != 0

            //Check X
            && pieceGrid[piece->getForm()[i].getX() + coord.getX() -1][piece->getForm()[i].getY() + coord.getY()] != 0
            && pieceGrid[piece->getForm()[i].getX() + coord.getX() +1][piece->getForm()[i].getY() + coord.getY()] != 0) {

            return false;
        }
    }


    return true;
}

