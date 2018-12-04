#include "Coordinate.h"

/**
 *
 */
Coordinate::Coordinate() {

}

/**
 *
 * @param x
 * @param y
 */
Coordinate::Coordinate(int x, int y) {
    this->x = x;
    this->y = y;
}

/**
 *
 * @return
 */
int Coordinate::getX() const {
    return x;
}

/**
 *
 * @param x
 */
void Coordinate::setX(int x) {
    Coordinate::x = x;
}

/**
 *
 * @return
 */
int Coordinate::getY() const {
    return y;
}

/**
 *
 * @param y
 */
void Coordinate::setY(int y) {
    Coordinate::y = y;
}
