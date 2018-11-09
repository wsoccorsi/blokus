#ifndef BLOKUS_TILE_GRID_H
#define BLOKUS_TILE_GRID_H

#include <vector>
#include "Tile.h"
#include "Drawable.h"
#include "Piece.h"
#include "Coordinate.h"


class TileGrid: public Drawable {
public:
    TileGrid();
    TileGrid(int x, int y, int x_tiles, int y_tiles);

    void draw(int width, int height) override;

    Coordinate screenPosToCoord(Coordinate coord);

    bool pieceFits(Piece* piece, Coordinate coord);
    void placePiece(Piece* piece, Coordinate coord);

protected:
    int x_tiles;
    int y_tiles;

    std::vector<std::vector<Tile*>> tiles;
};


#endif //BLOKUS_TILE_GRID_H
