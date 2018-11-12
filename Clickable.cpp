#include "Clickable.h"

Clickable::Clickable() {
    this->clickPriority = 10;
}

Clickable::Clickable(int clickPriority) {
    this->clickPriority = clickPriority;
}

void Clickable::onClick(Coordinate coord) {

}

bool Clickable::isInBounds(Coordinate coord) {
    return false;
}

int Clickable::getClickPriority() {
    return clickPriority;
}

void Clickable::setClickPriority(int clickPriority) {
    Clickable::clickPriority = clickPriority;
}
