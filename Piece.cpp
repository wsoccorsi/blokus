#include <iostream>
#include "Piece.h"
#include "Blokus.h"
#include "Player.h"


Piece::Piece() {

}

/**
 * Piece constructor to set blokus, form, player, x, y and tiles
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
 * draws piece
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
 * rotates piece left
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
 * rotates piece Right
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
 * Flips Piece
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
 * moves piece to certain coord
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
 * onClick for the piece that impletements movement and placement
 *
 * @param coord
 */
void Piece::onClick(Coordinate coord) {
    Clickable::onClick(coord);

    if (blokus->clickedPiece == nullptr && blokus->getCurrentPlayer() == player) {
        blokus->clickedPiece = this;

        this->setZ(15);
        MainWindow::updateDrawables();

        tileGrid->removePiece(this);

        moveTo(Coordinate(blokus->getMouseX() - Tile::TILE_SIZE / 2, blokus->getMouseY() - Tile::TILE_SIZE / 2));
        blokus->getEventListener().on(Blokus::Event::MOUSE_MOVE, [=] {
            if (blokus->clickedPiece == nullptr) {
                return EventHandler::ReturnType::POP;
            }
            moveTo(Coordinate(blokus->getMouseX() - Tile::TILE_SIZE / 2, blokus->getMouseY() - Tile::TILE_SIZE / 2));
            return EventHandler::ReturnType::CONTINUE;
        });
    }
}

/**
 * Checks in the piece is in bounds
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
 * updates tile where piece is placed
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
 * getter for form = vector of tiles for a piece
 *
 * @return
 */
std::vector<Coordinate> Piece::getForm() const{
    return form;
}

/**
 * makes sure u can only place a piece on the corner of your piece
 *
 * @return
 */
std::vector<Coordinate> Piece::getCornerForm() const {
    std::vector<Coordinate> cornerForm = std::vector<Coordinate>();
    for (Coordinate formCoord : form) {
        std::vector<Coordinate> cornersForTile = {
            Coordinate(1, 1),
            Coordinate(1, -1),
            Coordinate(-1, 1),
            Coordinate(-1, -1)
        };
        for (Coordinate edge : std::vector<Coordinate> {
                Coordinate(0, 1),
                Coordinate(0, -1),
                Coordinate(1, 0),
                Coordinate(-1, 0)
        }) {
            Coordinate relativeEdgePosition = formCoord + edge;
            for (Coordinate otherFormCoord : form) {
                if (otherFormCoord == relativeEdgePosition) {
                    for (Coordinate cornerToRemove : std::vector<Coordinate> {
                        edge + Coordinate(edge.getY(), edge.getX()),
                        edge + Coordinate(edge.getY() * -1, edge.getX() * -1)
                    }) {
                        for (int i = 0; i < cornersForTile.size(); i++) {
                            if (cornersForTile[i] == cornerToRemove){
                                cornersForTile.erase(cornersForTile.begin() + i); //removes the piece at this index
                                break;
                            }
                        }
                    }
                }
            }
        }
        for (Coordinate cornerForTile : cornersForTile) {
            cornerForm.push_back(formCoord + cornerForTile);
        }
    }
    return cornerForm;
}

/**
 * getter for tiles
 *
 * @return
 */
std::vector<Tile *> Piece::getTiles()  {
    return tiles;
}

/**
 * getter for plater
 *
 * @return
 */
Player *Piece::getPlayer() {
    return this->player;
}

/**
 * getter for tile grid
 *
 * @return
 */
TileGrid *Piece::getTileGrid() const {
    return tileGrid;
}

/**
 * setter for tile grid
 *
 * @param tileGrid
 */
void Piece::setTileGrid(TileGrid *tileGrid) {
    Piece::tileGrid = tileGrid;
}


