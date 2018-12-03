#include "Player.h"

Player::Player(Blokus* blokus, Color color, std::string title, Coordinate trayCoord) {
    this->blokus = blokus;
    this->color = color;
    this->title = title;

    this->pieces = std::vector<Piece*>();

    this->tray = new Tray(blokus, this, trayCoord.getX(), trayCoord.getY(), 20, 10);
    MainWindow::addDrawable(tray);


}

const Color &Player::getColor() const {
    return color;
}

void Player::setColor(const Color &color) {
    Player::color = color;
}

const std::string &Player::getTitle() const {
    return title;
}

void Player::setTitle(const std::string &title) {
    Player::title = title;
}

Tray *Player::getTray() const {
    return tray;
}

void Player::setTray(Tray *tray) {
    Player::tray = tray;
}
