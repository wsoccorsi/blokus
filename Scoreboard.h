#ifndef BLOKUS_SCOREBOARD_H
#define BLOKUS_SCOREBOARD_H


#include "Drawable.h"

class Scoreboard: public Drawable {
public:
    Scoreboard();
    Scoreboard(int x, int y);

    void draw(int width, int height) override;

    void setScore(int score);
    int getScore() const;

protected:
    int score;
};


#endif //BLOKUS_SCOREBOARD_H
