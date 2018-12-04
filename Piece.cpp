#include <iostream>
#include "Piece.h"
#include "Blokus.h"
#include "Player.h"

/**
 *
 */
Piece::Piece() {

}

/**
 *
 * @param blokus
 * @param form
 * @param player
 * @param x
 * @param y
 */
Piece::Piece(Blokus* blokus, std::vector<Coordinate> form, Player* player, int x, int y): Drawable(x, y, 3), Clickable(1) {
    this->blokus = blokus;
    this->form = form;
    this->player = player;
    this->x = x;
    this->y = y;

    this->tiles = std::vector<Tile*>();

    for (Coordinate coord : form) {
        Tile* tile = new Tile(x + coord.getX() * Tile::TILE_SIZE, y + coord.getY() * Tile::TILE_SIZE);
        tile->setColor(player->getColor());
        this->tiles.push_back(tile);
    }
}

/**
 *
 * @param blokus
 * @param form
 * @param player
 */
Piece::Piece(Blokus *blokus, std::vector<Coordinate> form, Player* player): Piece(blokus, form, player, 0, 0) {}

/**
 *
 * @param width
 * @param height
 */
void Piece::draw(int width, int height) {
    Drawable::draw(width, height);
    for (Tile* tile : tiles) {
        tile->draw(width, height);
    }
}

/**
 *
 */
void Piece::rotateLeft() {
    int tempX = 0;
    int tempY = 0;
    for (int i = 0; i < form.size(); ++i){
        tempX = form[i].getX();
        tempY = form[i].getY();
        form[i].setX(tempY);
        form[i].setY(tempX*-1);

    }

}

/**
 *
 */
void Piece::rotateRight() {
    int tempX = 0;
    int tempY = 0;
    for (int i = 0; i < form.size(); ++i){
        tempX = form[i].getX();
        tempY = form[i].getY();
        form[i].setX(tempY*-1);
        form[i].setY(tempX);

    }
}

/**
 *
 */
void Piece::flip() {
    int tempY = 0;
    for (int i = 0; i < form.size(); ++i){
        tempY = form[i].getY();
        form[i].setY(tempY*-1);

    }
}

/**
 *
 * @param coord
 */
void Piece::moveTo(Coordinate coord) {
    x = coord.getX();
    y = coord.getY();
    updateTiles();
    blokus->update();
}

/**
 *
 * @param coord
 */
void Piece::onClick(Coordinate coord) {
    Clickable::onClick(coord);
    std::cout << "piece clicked" << std::endl;
    int previousZ = this->getZ();
    this->setZ(15);
    MainWindow::updateDrawables();

    if (blokus->clickedPiece == nullptr && blokus->getCurrentPlayer() == player) {
        blokus->clickedPiece = this;
        moveTo(Coordinate(blokus->getMouseX() - Tile::TILE_SIZE / 2, blokus->getMouseY() - Tile::TILE_SIZE / 2));
        blokus->getEventListener().on(Blokus::Event::MOUSE_MOVE, [=] {
            if (blokus->clickedPiece == nullptr) {
                this->setZ(previousZ);
                MainWindow::updateDrawables();
                return EventHandler::ReturnType::POP;
            }
            moveTo(Coordinate(blokus->getMouseX() - Tile::TILE_SIZE / 2, blokus->getMouseY() - Tile::TILE_SIZE / 2));
            return EventHandler::ReturnType::CONTINUE;
        });
    }
}

/**
 *
 * @param coord
 * @return
 */
bool Piece::isInBounds(Coordinate coord) {
    if (blokus->clickedPiece == this) {
        return false;
    }
    for (Tile* tile : tiles) {
        if (tile->isInBounds(coord)) {
            return true;
        }
    }
    return false;
}

/**
 *
 */
void Piece::updateTiles() {
    for (int i = 0; i < form.size(); i++) {
        Coordinate coord = form[i];
        tiles[i]->setX(x + coord.getX() * Tile::TILE_SIZE);
        tiles[i]->setY(y + coord.getY() * Tile::TILE_SIZE);
    }
}

/**
 *
 * @return
 */
std::vector<Coordinate> Piece::getForm() const{
    return form;
}

/**
 *
 * @return
 */
std::vector<Tile *> Piece::getTiles()  {
    return tiles;
}

/**
 *
 * @return
 */
Player *Piece::getPlayer() {
    return this->player;
}


