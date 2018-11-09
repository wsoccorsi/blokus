#include "Blokus.h"
#include "Tray.h"

Blokus::Blokus(int width, int height): MainWindow("Blokus", width, height) {
    board = new TileGrid(30, 30, 20, 20);
    addDrawable(board);

    Tray* tray = new Tray(30, 450, 10, 5);
    addDrawable(tray);

    std::vector<Coordinate> form = std::vector<Coordinate>();
    form.push_back(Coordinate(0, 0));
    form.push_back(Coordinate(1, 0));
    form.push_back(Coordinate(2, 0));
    form.push_back(Coordinate(2, 1));
    Piece* piece = new Piece(form, 10, 10);
    addDrawable(piece);
}
