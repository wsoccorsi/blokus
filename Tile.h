#ifndef BLOKUS_TILE_H
#define BLOKUS_TILE_H

#include "Drawable.h"
#include <vector>
#include "Coordinate.h"
#include "Clickable.h"


class Tile: public Drawable, public Clickable {
public:
    Tile(int x, int y);
    void draw(int width, int height) override;

    void setColor(GLfloat red, GLfloat green, GLfloat blue);

    const static int TILE_SIZE = 20;

    void onClick(Coordinate coord) override;
    bool isInBounds(Coordinate coord) override;

protected:
    GLfloat red;
    GLfloat green;
    GLfloat blue;
};


#endif //BLOKUS_TILE_H
