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

std::vector<std::vector<Drawable*>> MainWindow::drawables = std::vector<std::vector<Drawable*>>();
std::vector<Clickable*> MainWindow::clickables = std::vector<Clickable*>();


MainWindow::MainWindow(std::string title, int width, int height) {
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
        drawables.emplace_back(std::vector<Drawable*>());
    }

    drawables[drawable->getZ()].push_back(drawable);
}

void MainWindow::addClickable(Clickable* clickable) {
    clickables.push_back(clickable);
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
        for (Clickable* clickable : clickables) {
            if (clickable->isInBounds(coord)) {
                clickable->onClick(coord);
            }
        }
    }
}

void MainWindow::onMouseMove(int x, int y) {
    //std::cout << x << ", " << y << std::endl;
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
