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

Coordinate Coordinate::operator+(const Coordinate& coord) const {
    return Coordinate(this->getX() + coord.getX(), this->getY() + coord.getY());
}

bool Coordinate::operator==(const Coordinate &rhs) const {
    return x == rhs.x &&
           y == rhs.y;
}

bool Coordinate::operator!=(const Coordinate &rhs) const {
    return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &os, const Coordinate &coordinate) {
    os << "x: " << coordinate.x << " y: " << coordinate.y;
    return os;
}
