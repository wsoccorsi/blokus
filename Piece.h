#ifndef BLOKUS_PIECE_H
#define BLOKUS_PIECE_H

#include <vector>
#include "Coordinate.h"
#include "Drawable.h"
#include "Tile.h"
#include "Clickable.h"


class Piece: public Drawable, public Clickable {
public:
    Piece();
    Piece(std::vector<Coordinate> form, int x, int y);

    void draw(int width, int height) override;

    void rotateLeft();
    void rotateRight();
    void flip();
    void moveTo(Coordinate coord);

    void onClick(Coordinate coord) override;
    bool isInBounds(Coordinate coord) override;

private:
    int x;
    int y;
    std::vector<Coordinate> form;
    std::vector<Tile*> tiles;
};


#endif //BLOKUS_PIECE_H
