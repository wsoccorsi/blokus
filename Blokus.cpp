#include "Blokus.h"
#include "Tray.h"

Blokus::Blokus(int width, int height): MainWindow("Blokus", width, height) {
    board = new TileGrid(30, 30, 20, 20);
    addDrawable(board);

    Tray* tray = new Tray(30, 450, 10, 5);
    addDrawable(tray);
}
