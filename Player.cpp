#include "Player.h"

Player::Player(Blokus* blokus, std::string title, Coordinate trayCoord) {
    this->title = title;
    this->blokus = blokus;

    this->pieces = std::vector<Piece*>();

    this->tray = new Tray(blokus, this, trayCoord.getX(), trayCoord.getY(), 20, 10);
    MainWindow::addDrawable(tray);
}
