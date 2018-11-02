//
// Created by William  Soccorsi on 10/31/18.
//
#include <stdlib.h>
#include "Computer.h"
#include "Piece.h"

#include <iostream>

using namespace std;


bool okflag = false;

Computer::Computer() {
itel = DUMB;
}

void Computer::setInteligence(enum intelligence i) {
    itel = i;
}



/**
 * computerMove functions based on the computers set intelligence. If
 * the intelligence of the computer is dumb then the lowest scoring block that fits
 * is set into place. If the intelligence of the computer is smart then the computer
 * places the highest scoring block that fits. Everything here is based on the
 * ideology that the unplayedPieces are all sorted from lowest to highest scoring.
 */
void Computer::computerMove() {
    bool piecePlacement = false;

    /**
     * If the iteligence of the computer is set to dumb then the computer
     * will place one of the lowest scoring blocks first
     */
    if (itel == DUMB){

        Piece p;
        vector<Piece> unplayedPieces = p.unplayedPieces();


        while (!piecePlacement){
            Piece p; // just using to link to avoid creation of static calls

            for (int i = 0; i < unplayedPieces.size(); i++){

                //edge case, if the index is the size of the vector, try and place one below
                    if (i == unplayedPieces.size()) {
                         if (p.isFit(unplayedPieces[unplayedPieces.size() - i])) {
                              p.placePiece(unplayedPieces[i]);
                              piecePlacement = true;
                              break;
                    }

               //if the lowest scoring+fitting piece fits
                    } else if (p.isFit(unplayedPieces[i])) {
                               p.placePiece(unplayedPieces[i]);
                               piecePlacement = true;
                               break;
                    }


                    else if (unplayedPieces.size() == i){
                        cout << "No More Moves!" << endl;

                }


            }

        }
    }


    /**
     * If the iteligence of the computer is set to smart then the computer
     * will place the highest scoring block that fits first.
     */
    else if (itel == SMART){

        Piece p;
        vector<Piece> unplayedPieces = p.unplayedPieces();

        while (!piecePlacement){
            Piece p; // just using to link to avoid creation of static calls

            for (int i = 0; i < unplayedPieces.size(); i++){

                //edge case on the first index because it will be out of bounds
                if (i == 0) {
                    if (p.isFit(unplayedPieces[unplayedPieces.size() - 1])) {
                        p.placePiece(unplayedPieces[unplayedPieces.size() - 1]);
                        piecePlacement = true;
                        break;
                    }
                 //if the highest scoring piece fits
                } else if (p.isFit(unplayedPieces[unplayedPieces.size() - i])) {
                    p.placePiece(unplayedPieces[unplayedPieces.size() - i]);
                    piecePlacement = true;
                    break;
                }
                //if nothing is played by the end of the loop
                else if (unplayedPieces.size() == i){
                    cout << "No More Moves!" << endl;

                }
                }


            }

        }


    }



