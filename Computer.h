//
// Created by William  Soccorsi on 12/2/18.
//

#include "Player.h"
#include "Board.h"

#ifndef BLOKUS_COMPUTER_H
#define BLOKUS_COMPUTER_H


class Computer : public Player {

public:
     Computer(Blokus* blokus, Color color, std::string title, Coordinate trayCoord, Board* board);

     void takeTurn();

protected:
    void animatePieceMove();
    PossibleMove getBestMove();
    int getMoveHeuristic(PossibleMove possibleMove);

};


#endif //BLOKUS_COMPUTER_H
