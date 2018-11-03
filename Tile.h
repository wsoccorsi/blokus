#ifndef BLOKUS_TILE_H
#define BLOKUS_TILE_H

#include "Drawable.h"


class Tile: public Drawable {
public:
    Tile(int x, int y);
    void draw(int width, int height) override;

    void setColor(GLfloat red, GLfloat green, GLfloat blue);

    const static int TILE_SIZE = 30;

protected:
    GLfloat red;
    GLfloat green;
    GLfloat blue;
};


#endif //BLOKUS_TILE_H
