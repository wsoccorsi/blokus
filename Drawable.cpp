#include "Drawable.h"

/**
 * Constructor for Drawable
 *
 */
Drawable::Drawable() {

}

/**
 * sets x, y, and z
 *
 * @param x
 * @param y
 * @param z
 */
Drawable::Drawable(int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

/**
 * draw method that take width and height
 *
 * @param width
 * @param height
 */
void Drawable::draw(int width, int height) {

}

/**
 * getter for x
 *
 * @return
 */
int Drawable::getX() const {
    return x;
}

/**
 * setter for x
 *
 * @param x
 */
void Drawable::setX(int x) {
    this->x = x;
}

/**
 * getter for y
 *
 * @return
 */
int Drawable::getY() const {
    return y;
}

/**
 * setter for y
 *
 * @param y
 */
void Drawable::setY(int y) {
    this->y = y;
}

/**
 * getter for z
 *
 * @return
 */
int Drawable::getZ() const {
    return z;
}

/**
 * setter for z
 *
 * @param z
 */
void Drawable::setZ(int z) {
    this->z = z;
}
