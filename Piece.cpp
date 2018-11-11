#include <iostream>
#include "Piece.h"
#include "Blokus.h"

Piece::Piece() {

}

Piece::Piece(Blokus* blokus, std::vector<Coordinate> form, int x, int y): Drawable(x, y, 1), Clickable() {
    this->blokus = blokus;
    this->form = form;
    this->x = x;
    this->y = y;

    this->tiles = std::vector<Tile*>();

    for (Coordinate coord : form) {
        Tile* tile = new Tile(x + coord.getX() * Tile::TILE_SIZE, y + coord.getY() * Tile::TILE_SIZE);
        tile->setColor(255, 0, 0);
        this->tiles.push_back(tile);
    }

    this->hovering = false;
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

void Piece::onClick(Coordinate coord) {
    Clickable::onClick(coord);
    std::cout << "piece clicked" << std::endl;

    if (blokus->clickedPiece == nullptr) {
        blokus->clickedPiece = this;
    }
}

bool Piece::isInBounds(Coordinate coord) {
    for (Tile* tile : tiles) {
        if (tile->isInBounds(coord)) {
            return true;
        }
    }
    return false;
}
