#include <iostream>
#include "Blokus.h"
#include <string>
#include <GLUT/glut.h>
#include "EventListener.h"

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    Blokus* blokus = new Blokus();

    glutMainLoop();
}