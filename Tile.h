#ifndef BLOKUS_TILE_H
#define BLOKUS_TILE_H

#include "Drawable.h"
#include <vector>
#include "Coordinate.h"


class Tile: public Drawable {
public:
    Tile(int x, int y);
    void draw(int width, int height) override;

    void setColor(GLfloat red, GLfloat green, GLfloat blue);

    const static int TILE_SIZE = 20;

protected:
    GLfloat red;
    GLfloat green;
    GLfloat blue;
};


#endif //BLOKUS_TILE_H
