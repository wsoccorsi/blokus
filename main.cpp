#include <iostream>
#include "MainWindow.h"
#include <string>
#include <GLUT/glut.h>

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    MainWindow* mainWindow = new MainWindow("test window");

    glutMainLoop();
}