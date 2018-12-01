#ifndef BLOKUS_TRAY_H
#define BLOKUS_TRAY_H

#include "TileGrid.h"

class Tray: public TileGrid {
public:
    Tray(int x, int y, int tiles_x, int tiles_y);

    bool isValidMove(Piece *piece, Coordinate coord) override;
};


#endif //BLOKUS_TRAY_H
