#include "Color.h"

/**
 *
 */
Color::Color() {
    this->r = 0;
    this->g = 0;
    this->b = 0;
}

/**
 *
 * @param r
 * @param g
 * @param b
 */
Color::Color(float r, float g, float b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

/**
 *
 * @return
 */
float Color::getR() const {
    return r;
}

/**
 *
 * @param r
 */
void Color::setR(float r) {
    Color::r = r;
}

/**
 *
 * @return
 */
float Color::getG() const {
    return g;
}

/**
 *
 * @param g
 */
void Color::setG(float g) {
    Color::g = g;
}

/**
 *
 * @return
 */
float Color::getB() const {
    return b;
}

/**
 *
 * @param b
 */
void Color::setB(float b) {
    Color::b = b;
}
