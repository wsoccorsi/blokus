#include "Blokus.h"

Blokus::Blokus(int width, int height): MainWindow("Blokus", width, height) {
    board = new TileGrid(100, 100, 10, 10);

    addDrawable(board);
}
