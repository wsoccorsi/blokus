#ifndef BLOKUS_BLOKUS_H
#define BLOKUS_BLOKUS_H


#include "MainWindow.h"
#include "TileGrid.h"

class Blokus: public MainWindow {
public:
    explicit Blokus(int width=400, int height=500);

private:
    TileGrid* board;
};


#endif //BLOKUS_BLOKUS_H
