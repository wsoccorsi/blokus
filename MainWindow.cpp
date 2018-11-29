#include "MainWindow.h"
#include <iostream>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Coordinate.h"

std::string MainWindow::title = "";
int MainWindow::width = 0;
int MainWindow::height = 0;

int MainWindow::mouseX = 0;
int MainWindow::mouseY = 0;

EventHandler MainWindow::eventHandler = EventHandler();

std::vector<std::vector<Drawable*>> MainWindow::drawables = std::vector<std::vector<Drawable*>>();
std::vector<std::vector<Clickable*>> MainWindow::clickables = std::vector<std::vector<Clickable*>>();


MainWindow::MainWindow(std::string title, int width, int height) : EventHandler() {
    MainWindow::title = title;
    MainWindow::width = width;
    MainWindow::height = height;

    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glutInitWindowSize(width, height);
    glutCreateWindow("Main Window");

    glClearColor(0, 0, 0, 0);
    //glDisable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);

    glViewport(0, 0, width, height);

    glutReshapeFunc(onResize);
    glutMouseFunc(onClick);
    glutPassiveMotionFunc(onMouseMove);
    glutDisplayFunc(render);
}

void MainWindow::addDrawable(Drawable* drawable) {
    while (drawables.size() < drawable->getZ() + 1) {
        drawables.push_back(std::vector<Drawable*>());
    }

    drawables[drawable->getZ()].push_back(drawable);
}

void MainWindow::addClickable(Clickable* clickable) {
    while (clickables.size() < clickable->getClickPriority() + 1) {
        clickables.push_back(std::vector<Clickable*>());
    }
    clickables[clickable->getClickPriority()].push_back(clickable);
}

void MainWindow::update() {
    glutPostRedisplay();
}

void MainWindow::onResize(int width, int height) {
    MainWindow::width = width;
    MainWindow::height = height;
    glutPostRedisplay();
    std::cout << width << ", " << height << std::endl;
}

void MainWindow::onClick(int button, int state, int x, int y) {
    Coordinate coord = Coordinate(x, y);
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        for (std::vector<Clickable*> clickablesForLevel : clickables) {
            for (Clickable* clickable : clickablesForLevel) {
                if (clickable->isInBounds(coord)) {
                    clickable->onClick(coord);
                    return;
                }
            }
        }

    }
}

void MainWindow::onMouseMove(int x, int y) {
    mouseX = x;
    mouseY = y;
    eventHandler.fire(Event::MOUSE_MOVE);
}

void MainWindow::render() {
    glClear(GL_COLOR_BUFFER_BIT);
    //glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width-1, height-1, 0, -1, 1);

    for (std::vector<Drawable*> drawablesForZ : drawables) {
        for (Drawable* drawable : drawablesForZ) {
            drawable->draw(width, height);
        }
    }
    std::cout << "render" << std::endl;

    glutSwapBuffers();
}

EventHandler& MainWindow::getEventListener() {
    return eventHandler;
}

int MainWindow::getMouseX() {
    return mouseX;
}

int MainWindow::getMouseY() {
    return mouseY;
}
