#ifndef BLOKUS_CLICKABLE_H
#define BLOKUS_CLICKABLE_H

#include "Coordinate.h"


class Clickable {
public:
    Clickable();

    virtual void onClick(Coordinate coord);
    virtual bool isInBounds(Coordinate coord);
};


#endif //BLOKUS_CLICKABLE_H
