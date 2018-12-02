#include "Blokus.h"
#include "Player.h"
#include "Board.h"

Blokus::Blokus(int width, int height): MainWindow("Blokus", width, height) {
    this->clickedPiece = nullptr;

    board = new Board(this, 30, 30);
    addDrawable(board);

    Player* player = new Player(this, "player 1", Coordinate(30, 450));

}
