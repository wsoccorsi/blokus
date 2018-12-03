//
// Created by William  Soccorsi on 12/2/18.
//

#include "Player.h"

#ifndef BLOKUS_COMPUTER_H
#define BLOKUS_COMPUTER_H


class Computer : public Player {

private:




public:


     Computer();

     Computer(Blokus* blokus, Color color, std::string title, Coordinate trayCoord);

     const Color &getColor() const override;

     void setColor(const Color &color) override;

     void setTitle(const std::string &title) override;

     Tray *getTray() const override;

     void setTray(Tray *tray) override;


protected:
    Blokus* blokus;
    Color color;
    std::string title;

    std::vector<Piece*> pieces;
    Tray* tray;



};


#endif //BLOKUS_COMPUTER_H
