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

    int edgeCase = 0;
    int checkXPos = 1; int checkXNeg = -1;
    int checkYPos = 1; int checkYNeg = -1;
    Coordinate c;

    for (int i = 0; i < piece->getForm().size(); i++){
        c.setX(piece->getForm()[i].getX() + coord.getX());
        c.setY(piece->getForm()[i].getY() + coord.getY());


        if (c.getX() == 0 && c.getY() == 0){
            edgeCase = 1;
        }
        else if (c.getX() == 19 && c.getY() == 0){
            edgeCase = 2;
        }
        else if (c.getX() == 0 && c.getY() == 19){
            edgeCase = 3;
        }
        else if (c.getX() == 19 && c.getY() == 19){
            edgeCase = 4;
        }
        else if (c.getX() == 0){
            edgeCase = 5;
        }
        else if (c.getY() == 0){
            edgeCase = 6;
        }
        else if (c.getX() == 19){
            edgeCase = 7;
        }
        else if (c.getY() == 19){
            edgeCase = 8;
        }


    }


    switch (edgeCase){
        //do nothing
        case 0:
            break;

        case 1: //Top left corner
            checkXNeg = 0;
            checkYNeg = 0;
            break;
        case 2: //Top right corner
            checkXPos = 0;
            checkYNeg = 0;
            break;
        case 3: //Bottom left corner
            checkXNeg = 0;
            checkYPos = 0;
            break;
        case 4: //Bottom right corner
            checkXPos = 0;
            checkYPos = 0;
            break;
        case 5: //left side of the board
            checkXNeg = 0;
            break;
        case 6: //Top of the board
            checkYNeg = 0;
            break;
        case 7://right of board
            checkXPos = 0;
            break;
        case 8: //bottom of board
            checkYPos = 0;
            break;

    }




    for (int i = 0; i < piece->getForm().size(); ++i){


                if (
                        //Origin overlapping
                        pieceGrid[piece->getForm()[i].getX() + coord.getX()][piece->getForm()[i].getY() + coord.getY()] != 0



                        //Check Y
                        || pieceGrid[piece->getForm()[i].getX() + coord.getX()][piece->getForm()[i].getY() + coord.getY() + checkYNeg] != 0
                        || pieceGrid[piece->getForm()[i].getX() + coord.getX()][piece->getForm()[i].getY() + coord.getY() + checkYPos] != 0

                        //Check X but
                        || pieceGrid[piece->getForm()[i].getX() + coord.getX() + checkXNeg][piece->getForm()[i].getY() + coord.getY()] != 0
                        || pieceGrid[piece->getForm()[i].getX() + coord.getX() + checkXPos][piece->getForm()[i].getY() + coord.getY()] != 0) {


                    return false;
                }



}
    return true;

}
