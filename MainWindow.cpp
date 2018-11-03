#include "MainWindow.h"
#include <iostream>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

std::string MainWindow::title = "";
int MainWindow::width = 0;
int MainWindow::height = 0;


MainWindow::MainWindow(std::string title, int width, int height) {
    MainWindow::title = title;
    MainWindow::width = width;
    MainWindow::height = height;

    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowSize(width, height);
    glutCreateWindow("Main Window");

    glClearColor(0, 0, 0, 0); // moved this line to be in the init function
    glDisable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);

    glutDisplayFunc(render);
    glutReshapeFunc(onResize);
}

void MainWindow::onResize(int width, int height) {
    MainWindow::width = width;
    MainWindow::height = height;
    std::cout << width << ", " << height << std::endl;
}

void MainWindow::render() {
    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glOrtho(0, width-1, height-1, 0, -1, 1);

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(10, 10);
    glVertex2f(100, 10);
    glVertex2f(100, 100);
    glVertex2f(10, 100);
    glEnd();

    glFlush();

    std::cout << "render" << std::endl;
}