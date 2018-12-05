#include "TileGrid.h"
#include <iostream>
TileGrid::TileGrid() {}

/**
 *
 * @param x
 * @param y
 * @param x_tiles
 * @param y_tiles
 */
TileGrid::TileGrid(int x, int y, int x_tiles, int y_tiles): Drawable(x, y, 1) {
    this->x_tiles = x_tiles;
    this->y_tiles = y_tiles;

    this->tiles = std::vector<std::vector<Tile*>>();

    this->pieceGrid = std::vector<std::vector<Piece*>>();
    for (int i = 0; i < x_tiles; i++) {
        this->pieceGrid.push_back(std::vector<Piece*>(y_tiles));
    }

    this->pieces = std::vector<Piece*>();

    for (int x_tile = 0; x_tile < x_tiles; x_tile++) {
        std::vector<Tile*> column = std::vector<Tile*>();
        for (int y_tile = 0; y_tile < y_tiles; y_tile++) {
            Tile* tile = new Tile(x + x_tile * Tile::TILE_SIZE, y + y_tile * Tile::TILE_SIZE);
            tile->setColor(Color(0.81, 0.86, 0.88));
            column.push_back(tile);
        }
        tiles.push_back(column);
    }
}

/**
 *
 * @param width
 * @param height
 */
void TileGrid::draw(int width, int height) {
    Drawable::draw(width, height);
    for (std::vector<Tile*> column : tiles) {
        for (Tile* tile : column) {
            tile->draw(width, height);
        }
    }
}

/**
 *
 * @param coord
 * @return
 */
Coordinate TileGrid::screenPosToCoord(Coordinate coord) {
    if (coord.getX() > x + x_tiles * Tile::TILE_SIZE || coord.getX() < x ||
        coord.getY() > y + y_tiles * Tile::TILE_SIZE || coord.getY() < y) {
        return Coordinate(-1, -1);
    }
    return Coordinate((coord.getX() - x) / Tile::TILE_SIZE, (coord.getY() - y) / Tile::TILE_SIZE);
}

/**
 *
 * @param coord
 * @return
 */
Coordinate TileGrid::coordToScreenPos(Coordinate coord) {
    return Coordinate(x + coord.getX() * Tile::TILE_SIZE, y + coord.getY() * Tile::TILE_SIZE);
}

/**
 *
 * @param coord
 * @return
 */
Tile* TileGrid::screenPosToTile(Coordinate coord) {
    Coordinate gridCoord = screenPosToCoord(coord);
    if (gridCoord.getX() > -1) {
        return tiles[gridCoord.getX()][gridCoord.getY()];
    }
    return nullptr;
}

/**
 *
 * @param piece
 * @param coord
 * @return
 */
bool TileGrid::pieceIsWithinBounds(Piece *piece, Coordinate coord) {
    //First Find the Boundaries of the board
    std::vector<Coordinate> form = piece->getForm();
    bool inBounds = false;

    //iterating through form and checking boundaries
    for(int i = 0; i < form.size(); i++){
        if (piece->getTiles()[i]->getX() > (getX() + Tile::TILE_SIZE * (x_tiles-1))
         || piece->getTiles()[i]->getY() > (getY() + Tile::TILE_SIZE * (y_tiles-1))
         || piece->getTiles()[i]->getX() < getX()
         || piece->getTiles()[i]->getY() < getY()){
            return false;
        }
    }
    return true;
}

/**
 *
 * @param piece
 * @param coord
 * @return
 */
bool TileGrid::pieceOverlaps(Piece *piece, Coordinate coord) {
    for(Coordinate formCoord : piece->getForm()){
        if(pieceGrid[coord.getX()+formCoord.getX()][coord.getY()+formCoord.getY()] != nullptr){
            return true;
        }
    }
    return false;
}

/**
 *
 * @param piece
 * @param coord
 */
void TileGrid::placePiece(Piece* piece, Coordinate coord) {
    piece->moveTo(coordToScreenPos(coord));
    for (Coordinate formCoord : piece->getForm()) {
        this->pieceGrid[coord.getX() + formCoord.getX()][coord.getY() + formCoord.getY()] = piece;
    }
    this->pieces.push_back(piece);
}

/**
 *
 * @param piece
 */
void TileGrid::removePiece(Piece *piece) {
    Coordinate pieceCoord = screenPosToCoord(Coordinate(piece->getX(), piece->getY()));
    for (Coordinate formCoord : piece->getForm()) {
        this->pieceGrid[pieceCoord.getX() + formCoord.getX()][pieceCoord.getY() + formCoord.getY()] = nullptr;
    }

    for (int i = 0; i < getPieces().size(); i++){
        if (piece == getPieces()[i]){
            pieces.erase(pieces.begin() + i); //removes the piece at this index
            break;
        }
    }
}

/**
 *
 * @return
 */
std::vector<Piece*> TileGrid::getPieces() const {
    return pieces;
}