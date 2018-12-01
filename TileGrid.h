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
    Tile* screenPosToTile(Coordinate coord);
    Coordinate coordToScreenPos(Coordinate coord);

    virtual bool isValidMove(Piece* piece, Coordinate coord) = 0;

    bool pieceIsWithinBounds(Piece* piece, Coordinate coord);
    bool pieceOverlaps(Piece* piece, Coordinate coord);

    void placePiece(Piece* piece, Coordinate coord);
    void removePiece(Piece* piece);

protected:
    int x_tiles;
    int y_tiles;

    std::vector<std::vector<Tile*>> tiles;
    std::vector<std::vector<Piece*>> pieceGrid;
};


#endif //BLOKUS_TILE_GRID_H
