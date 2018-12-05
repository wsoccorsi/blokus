#include "Player.h"

/**
 *
 * @param blokus
 * @param color
 * @param title
 * @param trayCoord
 */
Player::Player(Blokus* blokus, Color color, std::string title, Coordinate trayCoord) {
    this->blokus = blokus;
    this->color = color;
    this->title = title;

    this->tray = new Tray(blokus, this, trayCoord.getX(), trayCoord.getY(), 20, 10);
    MainWindow::addDrawable(tray);


}

/**
 *
 * @return
 */
const Color &Player::getColor() const {
    return color;
}

/**
 *
 * @param color
 */
void Player::setColor(const Color &color) {
    Player::color = color;
}

/**
 *
 * @return
 */
const std::string &Player::getTitle() const {
    return title;
}

/**
 *
 * @param title
 */
void Player::setTitle(const std::string &title) {
    Player::title = title;
}

/**
 *
 * @return
 */
Tray *Player::getTray() const {
    return tray;
}

/**
 *
 * @param tray
 */
void Player::setTray(Tray *tray) {
    Player::tray = tray;
}
