#ifndef BLOKUS_BLOKUSTITLES_H
#define BLOKUS_BLOKUSTITLES_H


#include "Drawable.h"
#include "Player.h"

class BlokusTitles: public Drawable {
public:
    BlokusTitles();

    void draw(int width, int height) override;
    void endGame(Player* winner);

protected:
    Player* winner;

};


#endif //BLOKUS_BLOKUSTITLES_H
