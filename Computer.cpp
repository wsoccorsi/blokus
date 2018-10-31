//
// Created by William  Soccorsi on 10/31/18.
//
#include <stdlib.h>
#include "Computer.h"


bool okflag = false;

Computer::Computer() {
itel = DUMB;
}

void Computer::setInteligence(enum intelligence i) {
    itel = i;
}

void Computer::computerMove() {
    bool piecePlacement = false;

     //removes top three in the array
    if (itel == DUMB){
        while (!piecePlacement){
            piece p;
            int randNum = (rand() % 3) + 1;

            if (unplayedPiecies.size() > 3) {
                int bottomThree = unplayedPieces.size() - (unplayedPieces.size() - 3);
                placePiece(unplayedPieces[bottomThree]);
                piecePlacement = true;
            }

            //places last in the array
            else {
               int lastPiece = unplayedPiecies.size() - (unplayedPiecies.size() - 1);
                placePiece(unplayedPieices[lastPiece]);
                piecePlacement = true;
            }
        }
    }

    else if (itel == SMART){

    }
}


