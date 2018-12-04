#include "Tray.h"
#include "Blokus.h"

/**
 *
 * @param blokus
 * @param player
 * @param x
 * @param y
 * @param tiles_x
 * @param tiles_y
 */
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

/**
 *
 */
void Tray::createPieces() {
    // https://c2strategy.files.wordpress.com/2011/04/piecenamesall.png
    // TODO the rest of them
    //  I5
    this->placePiece(new Piece(blokus, std::vector<Coordinate> {
            Coordinate(0, 0),
            Coordinate(1, 0),
            Coordinate(2, 0),
            Coordinate(3, 0),
            Coordinate(4, 0)
    }, player), Coordinate(10, 0));

    //  N
    this->placePiece(new Piece(blokus, std::vector<Coordinate> {
            Coordinate(0, 0),
            Coordinate(1, 0),
            Coordinate(1, -1),
            Coordinate(2, -1),
            Coordinate(3, -1)
    }, player), Coordinate(11, 3));

    //  T4
    this->placePiece(new Piece(blokus, std::vector<Coordinate> {
            Coordinate(0, 0),
            Coordinate(1, 0),
            Coordinate(1, -1),
            Coordinate(2, 0),
    }, player), Coordinate(14, 4));

    //  V5
    this->placePiece(new Piece(blokus, std::vector<Coordinate> {
            Coordinate(0, 0),
            Coordinate(1, 0),
            Coordinate(2, 0),
            Coordinate(0, -1),
            Coordinate(0, -2),
    }, player), Coordinate(0, 7));

    //  T5
    this->placePiece(new Piece(blokus, std::vector<Coordinate> {
            Coordinate(0, 0),
            Coordinate(1, 0),
            Coordinate(2, 0),
            Coordinate(1, -1),
            Coordinate(1, -2),
    }, player), Coordinate(6, 7));

    //  U
    this->placePiece(new Piece(blokus, std::vector<Coordinate> {
            Coordinate(0, 0),
            Coordinate(0, -1),
            Coordinate(1, -1),
            Coordinate(2, -1),
            Coordinate(2, 0),
    }, player), Coordinate(9, 9));

    //  L5
    this->placePiece(new Piece(blokus, std::vector<Coordinate> {
            Coordinate(0, 0),
            Coordinate(0, 1),
            Coordinate(1, 0),
            Coordinate(2, 0),
            Coordinate(3, 0),
    }, player), Coordinate(0, 0));

    //  Y
    this->placePiece(new Piece(blokus, std::vector<Coordinate> {
            Coordinate(0, 0),
            Coordinate(1, 0),
            Coordinate(1, 1),
            Coordinate(2, 0),
            Coordinate(3, 0),
    }, player), Coordinate(11, 6));

    //  Z5
    this->placePiece(new Piece(blokus, std::vector<Coordinate> {
            Coordinate(0, 0),
            Coordinate(0, -1),
            Coordinate(1, 0),
            Coordinate(2, 0),
            Coordinate(2, 1),
    }, player), Coordinate(3, 5));

    //  W
    this->placePiece(new Piece(blokus, std::vector<Coordinate> {
            Coordinate(0, 0),
            Coordinate(0, -1),
            Coordinate(1, 0),
            Coordinate(1, 1),
            Coordinate(2, 1),
    }, player), Coordinate(16, 1));

    //  P
    this->placePiece(new Piece(blokus, std::vector<Coordinate> {
            Coordinate(0, 0),
            Coordinate(1, 0),
            Coordinate(0, 1),
            Coordinate(1, 1),
            Coordinate(0, 2),
    }, player), Coordinate(1, 2));

    //  X
    this->placePiece(new Piece(blokus, std::vector<Coordinate> {
            Coordinate(0, 0),
            Coordinate(1, 0),
            Coordinate(1, -1),
            Coordinate(1, 1),
            Coordinate(2, 0),
    }, player), Coordinate(17, 5));

    //  F
    this->placePiece(new Piece(blokus, std::vector<Coordinate> {
            Coordinate(0, 0),
            Coordinate(0, 1),
            Coordinate(1, 0),
            Coordinate(1, -1),
            Coordinate(2, 0),
    }, player), Coordinate(8, 2));

    //  Z4
    this->placePiece(new Piece(blokus, std::vector<Coordinate> {
            Coordinate(0, 0),
            Coordinate(0, -1),
            Coordinate(1, 0),
            Coordinate(1, 1),
    }, player), Coordinate(4, 8));

    //  I4
    this->placePiece(new Piece(blokus, std::vector<Coordinate> {
            Coordinate(0, 0),
            Coordinate(1, 0),
            Coordinate(2, 0),
            Coordinate(3, 0),
    }, player), Coordinate(5, 0));

    //  L4
    this->placePiece(new Piece(blokus, std::vector<Coordinate> {
            Coordinate(0, 0),
            Coordinate(0, -1),
            Coordinate(1, 0),
            Coordinate(2, 0),
    }, player), Coordinate(4, 2));

    //  O
    this->placePiece(new Piece(blokus, std::vector<Coordinate> {
            Coordinate(0, 0),
            Coordinate(0, -1),
            Coordinate(1, -1),
            Coordinate(1, 0),
    }, player), Coordinate(9, 5));

    //  I3
    this->placePiece(new Piece(blokus, std::vector<Coordinate> {
            Coordinate(0, 0),
            Coordinate(1, 0),
            Coordinate(2, 0),
    }, player), Coordinate(15, 7));

    //  V3
    this->placePiece(new Piece(blokus, std::vector<Coordinate> {
            Coordinate(0, 0),
            Coordinate(1, 0),
            Coordinate(1, 1),
    }, player), Coordinate(18, 0));

    //  2
    this->placePiece(new Piece(blokus, std::vector<Coordinate> {
            Coordinate(0, 0),
            Coordinate(1, 0),
    }, player), Coordinate(13, 8));

    //  1
    this->placePiece(new Piece(blokus, std::vector<Coordinate> {
            Coordinate(0, 0),
    }, player), Coordinate(6, 4));

    for (Piece* piece : this->pieces) {
        MainWindow::addDrawable(piece);
        MainWindow::addClickable(piece);
    }

}

/**
 *
 * @param piece
 * @param coord
 * @return
 */
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
