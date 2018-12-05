#ifndef BLOKUS_BLOKUS_H
#define BLOKUS_BLOKUS_H

#include "MainWindow.h"
#include "TileGrid.h"
#include "EventHandler.h"

class Blokus: public MainWindow {
public:
    explicit Blokus(int width=1300, int height=850);
    Piece* clickedPiece;

    Player *getCurrentPlayer() const;
    void nextPlayerTurn();



protected:
    TileGrid* board;
    Player* currentPlayer;
    std::vector<Player* > players;
    int indexPlayers;
};


#endif //BLOKUS_BLOKUS_H
