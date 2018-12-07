#include "Coordinate.h"

/**
 * Constructor for Coordinate
 *
 */
Coordinate::Coordinate() {

}

/**
 * Sets x and y
 *
 * @param x
 * @param y
 */
Coordinate::Coordinate(int x, int y) {
    this->x = x;
    this->y = y;
}

/**
 *  getter for x
 *
 * @return
 */
int Coordinate::getX() const {
    return x;
}

/**
 * setter for x
 *
 * @param x
 */
void Coordinate::setX(int x) {
    Coordinate::x = x;
}

/**
 * getter for y
 *
 * @return
 */
int Coordinate::getY() const {
    return y;
}

/**
 *  setter for Y
 *
 * @param y
 */
void Coordinate::setY(int y) {
    Coordinate::y = y;
}

/**
 *
 *
 * @param coord
 * @return
 */
Coordinate Coordinate::operator+(const Coordinate& coord) const {
    return Coordinate(this->getX() + coord.getX(), this->getY() + coord.getY());
}

/**
 *
 * @param rhs
 * @return
 */
bool Coordinate::operator==(const Coordinate &rhs) const {
    return x == rhs.x &&
           y == rhs.y;
}

/**
 *
 * @param rhs
 * @return
 */
bool Coordinate::operator!=(const Coordinate &rhs) const {
    return !(rhs == *this);
}

/**
 *
 * @param os
 * @param coordinate
 * @return
 */
std::ostream &operator<<(std::ostream &os, const Coordinate &coordinate) {
    os << "x: " << coordinate.x << " y: " << coordinate.y;
    return os;
}
