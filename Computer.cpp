//
// Created by William  Soccorsi on 12/2/18.
//

#include "Computer.h"



Computer::Computer(Blokus* blokus, Color color, std::string title, Coordinate trayCoord)
                    : Player(blokus, color, title, trayCoord) {



}

const Color &Computer::getColor() const {
    return color;
}

void Computer::setColor(const Color &color) {
    Computer::color = color;
}


void Computer::setTitle(const std::string &title) {
    Computer::title = title;
}

Tray *Computer::getTray() const {
    return tray;
}

void Computer::setTray(Tray *tray) {
    Computer::tray = tray;
}