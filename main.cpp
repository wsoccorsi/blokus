#include <iostream>
#include "Blokus.h"
#include <string>
#include <GLUT/glut.h>
#include "EventHandler.h"

// TODO
// - create the rest of the pieces
// - piece rotation
// - tray rotation w/ automatic piece rotation (so we dont have to place all the pieces in every tray)
// - maintain state of current player's turn
// - board

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    Blokus* blokus = new Blokus();

    glutMainLoop();
}