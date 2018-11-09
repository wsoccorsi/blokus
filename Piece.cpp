#include "Piece.h"

Piece::Piece() {

}

Piece::Piece(std::vector<Coordinate> form, int x, int y): Drawable(x, y, 1) {
    this->form = form;
    this->x = x;
    this->y = y;

    this->tiles = std::vector<Tile*>();

    for (Coordinate coord : form) {
        Tile* tile = new Tile(x + coord.getX() * Tile::TILE_SIZE, y + coord.getY() * Tile::TILE_SIZE);
        tile->setColor(255, 0, 0);
        this->tiles.push_back(tile);
    }
}

void Piece::draw(int width, int height) {
    Drawable::draw(width, height);
    for (Tile* tile : tiles) {
        tile->draw(width, height);
    }
}

void Piece::rotateLeft() {

}

void Piece::rotateRight() {

}

void Piece::flip() {

}

void Piece::moveTo(Coordinate coord) {

}
