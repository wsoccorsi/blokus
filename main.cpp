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
#include "EventListener.h"

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    Blokus* blokus = new Blokus();

    glutMainLoop();
}