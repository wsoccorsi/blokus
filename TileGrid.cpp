#include "TileGrid.h"

TileGrid::TileGrid() {}

TileGrid::TileGrid(int x, int y, int x_tiles, int y_tiles): Drawable(x, y, 1) {
    this->x_tiles = x_tiles;
    this->y_tiles = y_tiles;

    this->tiles = std::vector<std::vector<Tile*>>();

    for (int x_tile = 0; x_tile < x_tiles; x_tile++) {
        std::vector<Tile*> column = std::vector<Tile*>();
        for (int y_tile = 0; y_tile < y_tiles; y_tile++) {
            Tile* tile = new Tile(x + x_tile * Tile::TILE_SIZE, y + y_tile * Tile::TILE_SIZE);
            tile->setColor(0.81, 0.86, 0.88);
            column.push_back(tile);
        }
        tiles.push_back(column);
    }
}

void TileGrid::draw(int width, int height) {
    Drawable::draw(width, height);
    for (std::vector<Tile*> column : tiles) {
        for (Tile* tile : column) {
            tile->draw(width, height);
        }
    }
}

Coordinate TileGrid::screenPosToCoord(Coordinate coord) {
    if (coord.getX() > x + x_tiles * Tile::TILE_SIZE || coord.getX() < x ||
        coord.getY() > y + y_tiles * Tile::TILE_SIZE || coord.getY() < y) {
        return Coordinate(-1, -1);
    }
    return Coordinate((coord.getX() - x) / Tile::TILE_SIZE, (coord.getY() - y) / Tile::TILE_SIZE);
}

bool TileGrid::pieceFits(Piece* piece, Coordinate coord) {
    return false;
}

void TileGrid::placePiece(Piece* piece, Coordinate coord) {

}
