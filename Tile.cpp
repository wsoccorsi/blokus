#include "Tile.h"

/**
 * sets color and inheirits drawable
 *
 * @param x
 * @param y
 */
Tile::Tile(int x, int y): Drawable(x, y, 2), Clickable(2) {
    this->color = Color();
}

/**
 *
 * @param color
 */
void Tile::setColor(Color color) {
    this->color = color;
}

/**
 * draws the tiles
 *
 * @param width
 * @param height
 */
void Tile::draw(int width, int height) {
    Drawable::draw(width, height); //WHY!!!

    glColor3f(color.getR()/2, color.getG()/2, color.getB()/2);
    glRectf(x, y, x + TILE_SIZE, y + TILE_SIZE);
    glColor3f(color.getR(), color.getG(), color.getB());
    glRectf(x + 1, y + 1, x + TILE_SIZE - 1, y + TILE_SIZE - 1);
}

/**
 * on click for tiles
 *
 * @param coord
 */
void Tile::onClick(Coordinate coord) {
    Clickable::onClick(coord);
    this->clickCallback(coord);
}

/**
 * check to see if the tiels are the right size
 *
 * @param coord
 * @return
 */
bool Tile::isInBounds(Coordinate coord) {
    return coord.getX() >= x && coord.getX() <= x + TILE_SIZE &&
           coord.getY() >= y && coord.getY() <= y + TILE_SIZE;
}

/**
 * setter for on click
 *
 * @param callback
 */
void Tile::setOnClick(std::function<void(Coordinate)> callback) {
    this->clickCallback = callback;
}

