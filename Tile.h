#ifndef BLOKUS_TILE_H
#define BLOKUS_TILE_H

#include "Drawable.h"
#include <vector>
#include "Coordinate.h"
#include "Clickable.h"
#include "EventHandler.h"
#include "Color.h"
#include <functional>


class Tile: public Drawable, public Clickable {
public:
    Tile(int x, int y);
    void draw(int width, int height) override;

    void setColor(Color color);

    const static int TILE_SIZE = 12;

    void onClick(Coordinate coord) override;
    bool isInBounds(Coordinate coord) override;

    void setOnClick(std::function<void(Coordinate)> callback);

protected:
    Color color;

    std::function<void(Coordinate)> clickCallback;
};


#endif //BLOKUS_TILE_H
