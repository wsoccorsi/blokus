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


        }
        return EventHandler::CONTINUE;
    });



    getEventListener().on(MainWindow::Event::KEY_LEFT, [=] {
        if(this->clickedPiece != NULL) {

            clickedPiece->rotateLeft();
            clickedPiece->updateTiles();
            update();

        }
        return EventHandler::CONTINUE;
    });

    getEventListener().on(MainWindow::Event::KEY_RIGHT, [=] {
        if(this->clickedPiece != NULL) {
            clickedPiece->rotateRight();
            clickedPiece->updateTiles();
            update();

        }
        return EventHandler::CONTINUE;
    });

    board = new Board(this, 475, 30);
    addDrawable(board);

    Player* player1 = new Player(this, "player 1", Coordinate(30, 30), 1);
    Player* player2 = new Player(this, "player 2", Coordinate(30, 235), 2);
    Player* player3 = new Player(this, "player 3", Coordinate(30, 440), 3);
    Player* player4 = new Player(this, "player 4", Coordinate(475, 440), 4);


}
