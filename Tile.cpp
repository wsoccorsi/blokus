#include "Tile.h"

Tile::Tile(int x, int y): Drawable(x, y, 2) {
    this->red = 0;
    this->green = 0;
    this->blue = 0;
}

void Tile::setColor(GLfloat red, GLfloat green, GLfloat blue) {
    this->red = red;
    this->green = green;
    this->blue = blue;
}

void Tile::draw(int width, int height) {
    Drawable::draw(width, height);

    glColor3f(red/2, green/2, blue/2);
    glRectf(x, y, x + TILE_SIZE, y + TILE_SIZE);
    glColor3f(red, green, blue);
    glRectf(x + 1, y + 1, x + TILE_SIZE - 1, y + TILE_SIZE - 1);
}
