#include "Blokus.h"
#include "Player.h"
#include "Board.h"
#include "Computer.h"
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

    getEventListener().on(MainWindow::Event::KEY_F2, [=] {
        std::cout << "\n"
                     ">>>>>>>>>>>>>>>>>>>>>>>>   GAME INSTRUCTIONS   <<<<<<<<<<<<<<<<<<<<<<<<<<<\n"
                     "\n\n";
        std::cout << "The standard rules of play for all variations of the game are as follows:\n"
                "\n"
                "    ~ Order of play is based on the color of pieces: blue, yellow, red, green.\n"
                "    ~ The first piece played of each color is placed in one of the board's four corners.\n"
                "       Each new piece played must be placed so that it touches at least one piece of \n"
                "       the same color, with only corner-to-corner contact allowed—edges cannot touch.\n"
                "       However, edge-to-edge contact is allowed when two pieces of different color are \n"
                "       involved.\n"
                "    ~ When a player cannot place a piece, he or she passes, and play continues as normal. \n"
                "       The game ends when no one can place a piece.\n"
                "    ~ When a game ends, the score is based on the number of squares in each player's \n"
                "       pieces on the board (e.g. a tetromino is worth 4 points). If a player played all \n"
                "       of his or her pieces, he or she gets a bonus score of +20 points if the last piece \n"
                "       played was a monomino, +15 points otherwise."
                "\n\n";
        update();
        return EventHandler::CONTINUE;
    });

    board = new Board(this, 350, 180);
    addDrawable(board);

    players = std::vector<Player*> {
        new Player(this, Color(0.87, 0.30, 0.31), Coordinate(70, 240), board, Coordinate(0, 0)),
        new Computer(this, Color(0.23, 0.24, 0.57), Coordinate(350, 25), board, Coordinate(19, 0)),
        new Player(this, Color(0.05, 0.47, 0.25), Coordinate(620, 240), board, Coordinate(19, 19)),
        new Computer(this, Color(0.90, 0.80, 0.29), Coordinate(350, 460), board, Coordinate(0, 19))
    };

    indexPlayers = 0;
    currentPlayer = players[indexPlayers];

    blokusTitles = new BlokusTitles();
    addDrawable(blokusTitles);

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
    if (currentPlayer->getPossibleMoves().empty()) {
        endGame();
        return;
    }
    if (Computer* computer = dynamic_cast<Computer*>(currentPlayer)) {
        computer->takeTurn();
    }
}

void Blokus::endGame() {
    std::cout << "end of game" << std::endl;
}


