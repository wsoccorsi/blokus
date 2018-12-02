#ifndef BLOKUS_PLAYER_H
#define BLOKUS_PLAYER_H

#include "Piece.h"
#include "Tray.h"

class Blokus;

class Player {
public:
    explicit Player(Blokus* blokus, std::string title, Coordinate trayCoord, int color);

private:
    Blokus* blokus;
    std::string title;

    std::vector<Piece*> pieces;
    Tray* tray;
};


#endif //BLOKUS_PLAYER_H
