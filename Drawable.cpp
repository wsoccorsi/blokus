#include "Drawable.h"

Drawable::Drawable() {

}

Drawable::Drawable(int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

void Drawable::draw(int width, int height) {

}

int Drawable::getX() const {
    return x;
}

void Drawable::setX(int x) {
    Drawable::x = x;
}

int Drawable::getY() const {
    return y;
}

void Drawable::setY(int y) {
    Drawable::y = y;
}

int Drawable::getZ() const {
    return z;
}

void Drawable::setZ(int z) {
    Drawable::z = z;
}
