//
// Created by William  Soccorsi on 12/2/18.
//

#include "Computer.h"


/**
 *
 * @param blokus
 * @param color
 * @param title
 * @param trayCoord
 */
Computer::Computer(Blokus* blokus, Color color, std::string title, Coordinate trayCoord)
                    : Player(blokus, color, title, trayCoord) {



}

/**
 *
 * @return
 */
const Color &Computer::getColor() const {
    return color;
}

/**
 *
 * @param color
 */
void Computer::setColor(const Color &color) {
    Computer::color = color;
}

/**
 *
 * @param title
 */
void Computer::setTitle(const std::string &title) {
    Computer::title = title;
}

/**
 *
 * @return
 */
Tray *Computer::getTray() const {
    return tray;
}

/**
 *
 * @param tray
 */
void Computer::setTray(Tray *tray) {
    Computer::tray = tray;
}