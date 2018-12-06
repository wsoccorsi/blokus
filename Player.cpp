#include "Player.h"

/**
 *
 * @param blokus
 * @param color
 * @param title
 * @param trayCoord
 */
Player::Player(Blokus* blokus, Color color, std::string title, Coordinate trayCoord, Board* board) {
    this->blokus = blokus;
    this->color = color;
    this->title = title;
    this->board = board;

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

std::vector<Player::PossibleMove> Player::getPossibleMoves() {
    std::vector<Player::PossibleMove> possibleMoves = std::vector<Player::PossibleMove>();
    for (int x = 0; x < board->getXTiles(); x++) {
        for (int y = 0; y < board->getYTiles(); y++) {
            Coordinate position = Coordinate(x, y);
            for (Piece* piece : tray->getPieces()) {
                std::vector<Coordinate> form = piece->getForm();
                for (int i = 0; i < 3; i++) {
                    Piece* testPiece = new Piece(blokus, form, piece->getPlayer(), 0, 0);
                    for (int rotationCount = 0; rotationCount < i; rotationCount++) {
                        testPiece->rotateRight();
                    }
                    if (board->isValidMove(testPiece, position)) {
                        possibleMoves.push_back(PossibleMove(piece, position, i));
                    }
                }
            }
        }
    }

    return possibleMoves;
}
