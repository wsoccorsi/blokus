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
<<<<<<< HEAD
#else
#include <GL/glut.h>
#endif
#include "EventListener.h"
=======
#include "EventHandler.h"

// TODO
// - create the rest of the pieces
// - piece rotation
// - tray rotation w/ automatic piece rotation (so we don't have to place all the pieces in every tray)
// - maintain state of current player's turn
// - board detect if player's piece is bordering an edge
// - board detect if player's piece is bordering a corner
// - algorithm to determine if player has a move they can make
// - algorithm to place a computer player's piece
// - click on trays at beginning of game to determine the number and order of humans vs. computers
// - make color scheme prettier
>>>>>>> abd9327f07374f8f82591d89226efa3450fddb32

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    Blokus* blokus = new Blokus();

    glutMainLoop();
}