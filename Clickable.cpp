#include "Clickable.h"

/**
 *  Clickable constructor
 *
 */
Clickable::Clickable() {
    this->clickPriority = 10;
}

/**
 *  declares click priority
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
 *  Checks if it in bounds
 *
 * @param coord
 * @return
 */
bool Clickable::isInBounds(Coordinate coord) {
    return false;
}

/**
 *  Click priority getter
 *
 * @return
 */
int Clickable::getClickPriority() {
    return clickPriority;
}

/**
 * click priority setter
 *
 * @param clickPriority
 */
void Clickable::setClickPriority(int clickPriority) {
    Clickable::clickPriority = clickPriority;
}
