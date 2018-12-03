#ifndef BLOKUS_BOARD_H
#define BLOKUS_BOARD_H

#include "TileGrid.h"
#include "Clickable.h"

#include "MainWindow.h"

class Blokus;

class Board: public TileGrid {
public:
    Board();
    Board(Blokus* blokus, int x, int y);

    bool doesBorderOwnEdge(Piece* piece, Coordinate coord);
    bool cornersDoTouch(Piece* piece, Coordinate coord);
    bool isValidMove(Piece *piece, Coordinate coord) override;

protected:
    Blokus* blokus;
};


#endif //BLOKUS_BOARD_H
