#include <iostream>
#include "Blokus.h"
#include <string>
#include <GLUT/glut.h>
#include "EventListener.h"

enum TestEnum {
    TEST1,
    TEST2,
    TEST3
};

int main(int argc, char** argv) {

    EventListener<TestEnum> test = EventListener<TestEnum>();

    glutInit(&argc, argv);

    Blokus* blokus = new Blokus();

    glutMainLoop();
}