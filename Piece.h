#ifndef BLOKUS_PIECE_H
#define BLOKUS_PIECE_H

#include <vector>
#include "Coordinate.h"
#include "Drawable.h"
#include "Tile.h"
#include "Clickable.h"


class Blokus;
class Player;
class TileGrid;

class Piece: public Drawable, public Clickable {
public:
    Piece();
    Piece(Blokus* blokus, std::vector<Coordinate> form, Player* player, int x, int y);
    Piece(Blokus* blokus, std::vector<Coordinate> form, Player* player);

    std::vector<Coordinate> getForm() const;
    std::vector<Tile *> getTiles();
    Player* getPlayer();

    std::vector<Coordinate> getTileCoordsWithCorners();

    void draw(int width, int height) override;

    void rotateLeft();
    void rotateRight();
    void flip();
    void moveTo(Coordinate coord);

    void onClick(Coordinate coord) override;
    bool isInBounds(Coordinate coord) override;

    void updateTiles();

    TileGrid *getTileGrid() const;

    void setTileGrid(TileGrid *tileGrid);

private:
    Blokus* blokus;
    std::vector<Coordinate> form;
    Player* player;
    TileGrid* tileGrid;


    std::vector<Tile*> tiles;

};


#endif //BLOKUS_PIECE_H
