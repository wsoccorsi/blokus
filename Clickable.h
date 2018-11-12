#ifndef BLOKUS_CLICKABLE_H
#define BLOKUS_CLICKABLE_H

#include "Coordinate.h"


class Clickable {
public:
    Clickable();
    Clickable(int clickPriority);

    virtual void onClick(Coordinate coord);
    virtual bool isInBounds(Coordinate coord);

    int getClickPriority();
    void setClickPriority(int clickPriority);

private:
    int clickPriority;
};


#endif //BLOKUS_CLICKABLE_H
