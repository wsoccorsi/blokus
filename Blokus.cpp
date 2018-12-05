#include "Blokus.h"
#include "Player.h"
#include "Board.h"
#include "Computer.h"
#include "Score.h"
#include <iostream>
using namespace std;

/**
 * Blokus constructor that holds the key stroke functions
 *
 * @param width
 * @param height
 */
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

    board = new Board(this, 420, 270);
    addDrawable(board);


    Score* score1 = new Score(35, 150);
    addDrawable(score1);

    Score* score2 = new Score(35, 170);
    addDrawable(score2);

    Score* score3 = new Score(35, 190);
    addDrawable(score3);

    Score* score4 = new Score(35, 210);
    addDrawable(score4);


    Player* player1 = new Player(this, Color(0.87, 0.30, 0.31), "player 1", Coordinate(70, 320));
    Player* player2 = new Player(this, Color(0.23, 0.24, 0.57), "player 2", Coordinate(420, 100));
    Computer* computer1  = new Computer(this, Color(0.05, 0.47, 0.25), "computer 1", Coordinate(830, 320));
    Computer* computer2 = new Computer(this, Color(0.90, 0.80, 0.29), "computer 2", Coordinate(420, 590));


    players.push_back(player1);
    players.push_back(player2);
    players.push_back(computer1);
    players.push_back(computer2);


    indexPlayers = 0;
    currentPlayer = players[indexPlayers];


}

/**
 * This class creates a Player function called getCurrentPlayer
 * this returns the current player
 *
 * @return
 */
Player *Blokus::getCurrentPlayer() const {
    return currentPlayer;
}

/**
 * Indexes through the players assigning the current player each time a
 * player places a piece
 *
 */
void Blokus::nextPlayerTurn() {
    indexPlayers = indexPlayers + 1;
    if(indexPlayers == players.size()){
        indexPlayers = 0;
    }
    currentPlayer = players[indexPlayers];

}


