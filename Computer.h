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
    Board* board;

    struct PossibleMove {
        PossibleMove() {
            this->piece = nullptr;
            this->position = Coordinate();
            this->rotation = 0;
            this->score = 0;
        }
        PossibleMove(Piece* piece, Coordinate position, int rotation) {
            this->piece = piece;
            this->position = position;
            this->rotation = rotation;
            this->score = 0;
        }
        Piece* piece;
        Coordinate position;
        int rotation;
        int score;
    };

    void animatePieceMove();
    PossibleMove getBestMove();
    std::vector<PossibleMove> getPossibleMoves();
    int getMoveHeuristic(PossibleMove possibleMove);

};


#endif //BLOKUS_COMPUTER_H
