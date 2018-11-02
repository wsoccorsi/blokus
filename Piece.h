//
// Created by William  Soccorsi on 11/2/18.
//

#ifndef BLOKUS_PIECIES_H
#define BLOKUS_PIECIES_H

#include <vector>

using namespace std;


class Piece {

private:
    int score;

public:
    Piece();


    vector<Piece> unplayedPieces();

    void placePiece(Piece p);

    bool isFit(Piece p);


};


#endif //BLOKUS_PIECIES_H
