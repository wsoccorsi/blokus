#include <iostream>
#include "Piece.h"
#include "Blokus.h"

Piece::Piece() {

}

Piece::Piece(Blokus* blokus, std::vector<Coordinate> form, int x, int y): Drawable(x, y, 3), Clickable(1) {
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
    x = coord.getX();
    y = coord.getY();
    updateTiles();
    blokus->update();
}

void Piece::onClick(Coordinate coord) {
    Clickable::onClick(coord);
    std::cout << "piece clicked" << std::endl;

    if (blokus->clickedPiece == nullptr) {
        blokus->clickedPiece = this;
        blokus->getEventListener().on(Blokus::Event::MOUSE_MOVE, [=] {
            if (blokus->clickedPiece == nullptr) {
                return EventListener::ReturnType::POP;
            }
            moveTo(Coordinate(blokus->getMouseX(), blokus->getMouseY()));
            return EventListener::ReturnType::CONTINUE;
        });
    }
}

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

void Piece::updateTiles() {
    for (int i = 0; i < form.size(); i++) {
        Coordinate coord = form[i];
        tiles[i]->setX(x + coord.getX() * Tile::TILE_SIZE);
        tiles[i]->setY(y + coord.getY() * Tile::TILE_SIZE);
    }
}
