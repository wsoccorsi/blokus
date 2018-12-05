#include <iostream>
#include "Board.h"
#include "Blokus.h"
#include <iostream>
using namespace std;

int turnCounter = 1;
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

    /**
     * Edge checking data field
     */
    bool isCorner = false;
    int checkXPos = 1;
    int checkXNeg = -1;
    int checkYPos = 1;
    int checkYNeg = -1;
    Coordinate c;
    Coordinate start;

    /**
     * Checking start positions
     */
    switch (turnCounter) {

        case 1:
            start.setX(0);
            start.setY(0);
            break;
        case 2:
            start.setX(19);
            start.setY(0);
            break;
        case 3:
            start.setX(19);
            start.setY(19);
            break;
        case 4:
            start.setX(0);
            start.setY(19);
            break;


    }

    /**
     * Only code that runs for the first 4 iterations
     */
    if (turnCounter <= 4) {
        for (int k = 0; k < piece->getForm().size(); ++k) {
            c.setX(piece->getForm()[k].getX() + coord.getX());
            c.setY(piece->getForm()[k].getY() + coord.getY());
            if (c.getX() == start.getX() && c.getY() == start.getY()) {
                turnCounter++;
                return true;
            }
        }
    }
    if (turnCounter > 4) {
        for (int i = 0; i < piece->getForm().size(); ++i) {

            /**
             * Calculating edge cases (out of bounds cords)
             */
            c.setX(piece->getForm()[i].getX() + coord.getX());
            c.setY(piece->getForm()[i].getY() + coord.getY());
            if (c.getX() == 0) {
                checkXNeg = 0;
            } else {
                checkXNeg = -1;
            }
            if (c.getY() == 0) {
                checkYNeg = 0;
            } else {
                checkYNeg = -1;
            }
            if (c.getX() == 19) {
                checkXPos = 0;
            } else {
                checkXPos = 1;
            }
            if (c.getY() == 19) {
                checkYPos = 0;
            } else {
                checkYPos = 1;
            }

            /**
             * Checking to make sure its not a face side of the same piece
             */
            if (pieceGrid[piece->getForm()[i].getX() + coord.getX()][piece->getForm()[i].getY() + coord.getY() + checkYNeg] != 0)
            {
                if (pieceGrid[piece->getForm()[i].getX() + coord.getX()][piece->getForm()[i].getY() + coord.getY() + checkYNeg]->getPlayer() == piece->getPlayer()){
                    return false;
                }
            }
            else if (pieceGrid[piece->getForm()[i].getX() + coord.getX()][piece->getForm()[i].getY() + coord.getY() + checkYPos] != 0) {
                if(pieceGrid[piece->getForm()[i].getX() + coord.getX()][piece->getForm()[i].getY() + coord.getY() + checkYPos]->getPlayer() == piece->getPlayer()){
                    return false;
                }
            }
            else if(pieceGrid[piece->getForm()[i].getX() + coord.getX() + checkXNeg][piece->getForm()[i].getY() + coord.getY()] != 0){
                if(pieceGrid[piece->getForm()[i].getX() + coord.getX() + checkXNeg][piece->getForm()[i].getY() + coord.getY()]->getPlayer()== piece->getPlayer()){
                    return false;
                }
            }
            else if(pieceGrid[piece->getForm()[i].getX() + coord.getX() + checkXPos][piece->getForm()[i].getY() + coord.getY()] != 0){
                if(pieceGrid[piece->getForm()[i].getX() + coord.getX() + checkXPos][piece->getForm()[i].getY() + coord.getY()]->getPlayer() == piece->getPlayer()){
                    return false;
                }
            }





            /**
            * Check for a corner of the same piece
            */
            for (int j = 0; j < piece->getForm().size(); ++j) {
                c.setX(piece->getForm()[j].getX() + coord.getX());
                c.setY(piece->getForm()[j].getY() + coord.getY());
                if (c.getX() == 0) {
                    checkXNeg = 0;
                } else {
                    checkXNeg = -1;
                }
                if (c.getY() == 0) {
                    checkYNeg = 0;
                } else {
                    checkYNeg = -1;
                }
                if (c.getX() == 19) {
                    checkXPos = 0;
                } else {
                    checkXPos = 1;
                }
                if (c.getY() == 19) {
                    checkYPos = 0;
                } else {
                    checkYPos = 1;
                }


                if (pieceGrid[piece->getForm()[j].getX() + coord.getX() + checkXNeg][piece->getForm()[j].getY() + coord.getY() + checkYNeg] != 0) {
                    if (pieceGrid[piece->getForm()[j].getX() + coord.getX() + checkXNeg][piece->getForm()[j].getY() + coord.getY() + checkYNeg]->getPlayer() == piece->getPlayer()) {
                        isCorner = true;
                    }

                } else if (pieceGrid[piece->getForm()[j].getX() + coord.getX() + checkXPos][piece->getForm()[j].getY() + coord.getY() + checkYPos] != 0) {

                    if (pieceGrid[piece->getForm()[j].getX() + coord.getX() + checkXPos][piece->getForm()[j].getY() + coord.getY() + checkYPos]->getPlayer() == piece->getPlayer()){
                    isCorner = true;
                }

                }
                else if (pieceGrid[piece->getForm()[j].getX() + coord.getX() + checkXPos][piece->getForm()[j].getY() + coord.getY() + checkYNeg] != 0) {
                    if (pieceGrid[piece->getForm()[j].getX() + coord.getX() + checkXPos][piece->getForm()[j].getY() + coord.getY() + checkYNeg]->getPlayer() == piece->getPlayer()) {
                        isCorner = true;
                    }
                } else if (pieceGrid[piece->getForm()[j].getX() + coord.getX() + checkXNeg][piece->getForm()[j].getY() + coord.getY() + checkYPos] != 0) {

                    if (pieceGrid[piece->getForm()[j].getX() + coord.getX()+ checkXNeg][piece->getForm()[j].getY() + coord.getY() + checkYPos]->getPlayer() == piece->getPlayer()) {
                        isCorner = true;

                    }
                }
            }
        }
    }
    if (isCorner) {
        return true;
    } else {
        return false;
    }
}




