#include "Board.h"

Board::Board() {

}

Board::Board(int x, int y, int x_tiles, int y_tiles): Drawable(x, y, 1) {
    this->x_tiles = x_tiles;
    this->y_tiles = y_tiles;
}

void Board::draw() {
    Drawable::draw();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(10, 10);
    glVertex2f(100, 10);
    glVertex2f(100, 100);
    glVertex2f(10, 100);
    glEnd();
}

