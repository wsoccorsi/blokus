#include "Color.h"

/**
 * Constructor for color
 *
 */
Color::Color() {
    this->r = 0;
    this->g = 0;
    this->b = 0;
}

/**
 * Declares R, G, B for coler
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
 *  R getter
 * @return
 */
float Color::getR() const {
    return r;
}

/**
 * R setter
 * @param r
 */
void Color::setR(float r) {
    Color::r = r;
}

/**
 * G Getter
 * @return
 */
float Color::getG() const {
    return g;
}

/**
 * G setter
 * @param g
 */
void Color::setG(float g) {
    Color::g = g;
}

/**
 * B getter
 * @return
 */
float Color::getB() const {
    return b;
}

/**
 * B setter
 * @param b
 */
void Color::setB(float b) {
    Color::b = b;
}
