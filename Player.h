#ifndef BLOKUS_PLAYER_H
#define BLOKUS_PLAYER_H

#include "Piece.h"
#include "Tray.h"

class Blokus;

class Player {

public:


    explicit Player(Blokus* blokus, Color color, std::string title, Coordinate trayCoord);

    virtual const Color &getColor() const;

    virtual void setColor(const Color &color);

    virtual const std::string &getTitle() const;

    virtual void setTitle(const std::string &title);

    virtual Tray *getTray() const;

    virtual void setTray(Tray *tray);


private:
    Blokus* blokus;
    Color color;
    std::string title;

    std::vector<Piece*> pieces;
    Tray* tray;

};


#endif //BLOKUS_PLAYER_H
