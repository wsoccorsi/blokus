#include "Blokus.h"

Blokus::Blokus(int width, int height): MainWindow("Blokus", width, height) {
    board = Board(100, 100, 50, 50);

    addDrawable(board);
}
