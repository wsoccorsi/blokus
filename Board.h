#ifndef BLOKUS_BOARD_H
#define BLOKUS_BOARD_H

#include <vector>
#include "Piece.h"
#include "Drawable.h"


class Board: public Drawable {
public:
    Board();
    Board(int x, int y, int x_tiles, int y_tiles);

private:
    int x_tiles;
    int y_tiles;
    std::vector<std::vector<Piece>> board;

    void draw() override;
};


#endif //BLOKUS_BOARD_H
