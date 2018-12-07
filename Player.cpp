#include "Player.h"

/**
 * Player constructor that sets blokus, color, board, start, tray, scoreboard
 *
 * @param blokus
 * @param color
 * @param title
 * @param trayCoord
 */
Player::Player(Blokus* blokus, Color color, Coordinate trayCoord, Board* board, Coordinate start, std::string title) {
    this->blokus = blokus;
    this->color = color;
    this->board = board;
    this->start = start;
    this->title = title;

    this->tray = new Tray(blokus, this, trayCoord.getX(), trayCoord.getY(), 20, 10);
    MainWindow::addDrawable(tray);

    this->scoreboard = new Scoreboard(this->tray->getX(), this->tray->getY() - 10);
    MainWindow::addDrawable(scoreboard);
}

/**
 * getter for color
 *
 * @return
 */
const Color &Player::getColor() const {
    return color;
}

/**
 * setter for color
 *
 * @param color
 */
void Player::setColor(const Color &color) {
    Player::color = color;
}

/**
 * getter for tray
 *
 * @return
 */
Tray *Player::getTray() const {
    return tray;
}

/**
 * stter for tray
 *
 * @param tray
 */
void Player::setTray(Tray *tray) {
    Player::tray = tray;
}

/**
 * getter for all possible moves
 *
 * @return
 */
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

/**
 * getter for start
 *
 * @return
 */
const Coordinate &Player::getStart() const {
    return start;
}

/**
 * getter for score
 *
 * @return
 */
int Player::getScore() const {
    return this->scoreboard->getScore();
}

/**
 * setter for score
 *
 * @param score
 */
void Player::setScore(int score){
    this->scoreboard->setScore(score);
}

const std::string &Player::getTitle() const {
    return title;
}

void Player::setTitle(const std::string &title) {
    Player::title = title;
}
