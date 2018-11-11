#include <iostream>
#include "Board.h"

Board::Board() {
    this->blokus = nullptr;
}

Board::Board(Blokus* blokus, int x, int y): TileGrid(x, y, 20, 20) {
    this->blokus = blokus;

    for (std::vector<Tile*> tileColumn: tiles) {
        for (Tile* tile : tileColumn) {
            MainWindow* mainWindow = (MainWindow*) this->blokus;
            mainWindow->addClickable(tile);
            tile->setOnClick([&] (Coordinate coord) {
                std::cout << coord.getX() << ", " << coord.getY() << std::endl;
            });
        }
    }
}