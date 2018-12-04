#include "Drawable.h"

/**
 *
 */
Drawable::Drawable() {

}

/**
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
 *
 * @param width
 * @param height
 */
void Drawable::draw(int width, int height) {

}

/**
 *
 * @return
 */
int Drawable::getX() const {
    return x;
}

/**
 *
 * @param x
 */
void Drawable::setX(int x) {
    Drawable::x = x;
}

/**
 *
 * @return
 */
int Drawable::getY() const {
    return y;
}

/**
 *
 * @param y
 */
void Drawable::setY(int y) {
    Drawable::y = y;
}

/**
 *
 * @return
 */
int Drawable::getZ() const {
    return z;
}

/**
 *
 * @param z
 */
void Drawable::setZ(int z) {
    Drawable::z = z;
}
