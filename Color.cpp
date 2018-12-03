#include "Color.h"

Color::Color() {
    this->r = 0;
    this->g = 0;
    this->b = 0;
}

Color::Color(float r, float g, float b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

float Color::getR() const {
    return r;
}

void Color::setR(float r) {
    Color::r = r;
}

float Color::getG() const {
    return g;
}

void Color::setG(float g) {
    Color::g = g;
}

float Color::getB() const {
    return b;
}

void Color::setB(float b) {
    Color::b = b;
}
