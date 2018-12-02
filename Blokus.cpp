#include "Blokus.h"
#include "Player.h"
#include "Board.h"

#include <iostream>
using namespace std;

Blokus::Blokus(int width, int height): MainWindow("Blokus", width, height) {
    this->clickedPiece = nullptr;

    getEventListener().on(MainWindow::Event::KEY_UP, [=] {
        if(this->clickedPiece != NULL) {

            clickedPiece->flip();
            clickedPiece->updateTiles();
            update();
            return EventHandler::CONTINUE;

        }
    });

    getEventListener().on(MainWindow::Event::KEY_LEFT, [=] {
        if(this->clickedPiece != NULL) {

            clickedPiece->rotateLeft();
            clickedPiece->updateTiles();
            update();
            return EventHandler::CONTINUE;
        }
    });

    getEventListener().on(MainWindow::Event::KEY_RIGHT, [=] {
        if(this->clickedPiece != NULL) {
            clickedPiece->rotateRight();
            clickedPiece->updateTiles();
            update();
            return EventHandler::CONTINUE;
        }
    });

    board = new Board(this, 30, 30);
    addDrawable(board);

    Player* player = new Player(this, "player 1", Coordinate(30, 450));

}
