#ifndef BLOKUS_BLOKUS_H
#define BLOKUS_BLOKUS_H

#include "MainWindow.h"
#include "TileGrid.h"
#include "EventHandler.h"
#include "Board.h"
#include "BlokusTitles.h"
#include "Scoreboard.h"

class Blokus: public MainWindow {
public:
    explicit Blokus(int width=960, int height=600);
    Piece* clickedPiece;

    Player *getCurrentPlayer() const;
    void nextPlayerTurn();

    void endGame();

protected:
    Board* board;
    Player* currentPlayer;
    std::vector<Player*> players;
    int indexPlayers;
    BlokusTitles* blokusTitles;

};


#endif //BLOKUS_BLOKUS_H
