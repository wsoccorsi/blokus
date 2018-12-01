#include "Tray.h"

Tray::Tray(int x, int y, int tiles_x, int tiles_y) : TileGrid(x, y, tiles_x, tiles_y) {

}

bool Tray::isValidMove(Piece *piece, Coordinate coord) {
    return true;
}
