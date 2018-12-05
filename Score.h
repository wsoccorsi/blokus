
#ifndef BLOKUS_SCORE_H
#define BLOKUS_SCORE_H

#include "Drawable.h"
#include "Blokus.h"
#include <string>
using namespace std;

class Score : public Drawable {

public:

    Score(int x, int y);

    void draw(int width, int height) override;

};



#endif //BLOKUS_SCORE_H
