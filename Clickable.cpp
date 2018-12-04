#include "Clickable.h"

/**
 *
 */
Clickable::Clickable() {
    this->clickPriority = 10;
}

/**
 *
 * @param clickPriority
 */
Clickable::Clickable(int clickPriority) {
    this->clickPriority = clickPriority;
}

/**
 *
 * @param coord
 */
void Clickable::onClick(Coordinate coord) {

}

/**
 *
 * @param coord
 * @return
 */
bool Clickable::isInBounds(Coordinate coord) {
    return false;
}

/**
 *
 * @return
 */
int Clickable::getClickPriority() {
    return clickPriority;
}

/**
 *
 * @param clickPriority
 */
void Clickable::setClickPriority(int clickPriority) {
    Clickable::clickPriority = clickPriority;
}
