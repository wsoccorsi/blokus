#include "Tray.h"
#include "Blokus.h"

Tray::Tray(Blokus* blokus, Player* player, int x, int y, int tiles_x, int tiles_y) : TileGrid(x, y, tiles_x, tiles_y) {
    this->blokus = blokus;
    this->player = player;

    for (std::vector<Tile*> tileColumn: tiles) {
        for (Tile* tile : tileColumn) {
            MainWindow* mainWindow = (MainWindow*) this->blokus;
            mainWindow->addClickable(tile);
            tile->setOnClick([&] (Coordinate coord) {
                if (this->blokus->clickedPiece != nullptr) {
                    Coordinate pieceCoord = screenPosToCoord(coord);
                    if (isValidMove(this->blokus->clickedPiece, pieceCoord)) {
                        placePiece(this->blokus->clickedPiece, pieceCoord);
                        this->blokus->clickedPiece = nullptr;
                    }
                }
            });
        }
    }

    createPieces();
}

void Tray::createPieces() {
    // https://c2strategy.files.wordpress.com/2011/04/piecenamesall.png
    // TODO the rest of them
    this->placePiece(new Piece(blokus, std::vector<Coordinate> {
            Coordinate(0, 0),
            Coordinate(1, 0),
            Coordinate(2, 0),
            Coordinate(3, 0),
            Coordinate(4, 0)
    }, player), Coordinate(0, 0));

    this->placePiece(new Piece(blokus, std::vector<Coordinate> {
            Coordinate(0, 0),
            Coordinate(1, 0),
            Coordinate(1, -1),
            Coordinate(2, -1),
            Coordinate(3, -1)
    }, player), Coordinate(6, 1));

    this->placePiece(new Piece(blokus, std::vector<Coordinate> {
            Coordinate(0, 0),
            Coordinate(1, 0),
            Coordinate(1, -1),
            Coordinate(2, 0),
    }, player), Coordinate(13, 1));

    for (Piece* piece : this->pieces) {
        MainWindow::addDrawable(piece);
        MainWindow::addClickable(piece);
    }
}

bool Tray::isValidMove(Piece *piece, Coordinate coord) {
    if (!pieceIsWithinBounds(piece, coord)) {
        return false;
    }
    if (pieceOverlaps(piece, coord)) {
        return false;
    }
    if (piece->getPlayer() != this->player) {
        return false;
    }
    return true;
}
