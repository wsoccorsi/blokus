#ifndef BLOKUS_TRAY_H
#define BLOKUS_TRAY_H

#include "TileGrid.h"
#include "MainWindow.h"

class Blokus;
class Player;

class Tray: public TileGrid {
public:
    Tray(Blokus* blokus, Player* player, int x, int y, int tiles_x, int tiles_y);

    bool isValidMove(Piece *piece, Coordinate coord) override;

protected:
    Blokus* blokus;
    Player* player;

    void createPieces();
};


#endif //BLOKUS_TRAY_H
