#ifndef BLOKUS_PLAYER_H
#define BLOKUS_PLAYER_H

#include "Piece.h"
#include "Tray.h"

class Blokus;

class Player {
public:
    explicit Player(Blokus* blokus, Color color, std::string title, Coordinate trayCoord);

    const Color &getColor() const;

    void setColor(const Color &color);

    const std::string &getTitle() const;

    void setTitle(const std::string &title);

    Tray *getTray() const;

    void setTray(Tray *tray);

private:
    Blokus* blokus;
    Color color;
    std::string title;

    std::vector<Piece*> pieces;
    Tray* tray;
};


#endif //BLOKUS_PLAYER_H
