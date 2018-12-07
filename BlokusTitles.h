#ifndef BLOKUS_BLOKUSTITLES_H
#define BLOKUS_BLOKUSTITLES_H


#include "Drawable.h"

class BlokusTitles: public Drawable {
public:
    BlokusTitles();

    void draw(int width, int height) override;
};


#endif //BLOKUS_BLOKUSTITLES_H
