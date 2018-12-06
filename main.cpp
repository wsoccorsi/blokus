#include <iostream>
#include "Blokus.h"
#include <string>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "EventHandler.h"

// TODO
// - (x) create the rest of the pieces
// - (X) piece rotation
// - (X) tray rotation w/ automatic piece rotation (so we don't have to place all the pieces in every tray)
// - (x) maintain state of current player's turn
// - (x) board detect if player's piece is bordering an edge
// - (x) board detect if player's piece is bordering a corner
// - (x) algorithm to determine if player has a move they can make
// - (x) algorithm to place a computer player's piece
// - click on trays at beginning of game to determine the number and order of humans vs. computers
// - (x) make color scheme prettier

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    Blokus* blokus = new Blokus();

    glutMainLoop();
}