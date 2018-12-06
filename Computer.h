//
// Created by William  Soccorsi on 12/2/18.
//

#include "Player.h"
#include "Board.h"

#ifndef BLOKUS_COMPUTER_H
#define BLOKUS_COMPUTER_H


class Computer : public Player {

public:
     Computer(Blokus* blokus, Color color, Coordinate trayCoord, Board* board, Coordinate start);

     void takeTurn();

protected:
    void animatePieceMove(Piece* piece, Coordinate to);
    PossibleMove getBestMove();
    int getMoveHeuristic(PossibleMove possibleMove);

};


#endif //BLOKUS_COMPUTER_H
