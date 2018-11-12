#ifndef BLOKUS_BLOKUS_H
#define BLOKUS_BLOKUS_H

#include "MainWindow.h"
#include "TileGrid.h"

class Blokus: public MainWindow, public EventListener<Blokus> {
public:
    enum Event {
        MOUSE_MOVE,
        MOUSE_CLICK
    };

    explicit Blokus(int width=900, int height=700);
    Piece* clickedPiece;

protected:
    TileGrid* board;
};


#endif //BLOKUS_BLOKUS_H
