#include "MainWindow.h"
#include <iostream>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Coordinate.h"

/**
 *
 */
std::string MainWindow::title = "";
int MainWindow::width = 0;
int MainWindow::height = 0;

int MainWindow::mouseX = 0;
int MainWindow::mouseY = 0;

EventHandler MainWindow::eventHandler = EventHandler();

std::vector<std::vector<Drawable*>> MainWindow::drawables = std::vector<std::vector<Drawable*>>();
std::vector<std::vector<Clickable*>> MainWindow::clickables = std::vector<std::vector<Clickable*>>();

bool MainWindow::animating = false;

/**
 *
 * @param title
 * @param width
 * @param height
 */
MainWindow::MainWindow(std::string title, int width, int height) : EventHandler() {
    MainWindow::title = title;
    MainWindow::width = width;
    MainWindow::height = height;

    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glutInitWindowSize(width, height);
    glutCreateWindow("Blokus Team 8");

    glClearColor(.9, .85, .7, 1);
    //glDisable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);

    glViewport(0, 0, width, height);

    glutReshapeFunc(onResize);
    glutMouseFunc(onClick);
    glutPassiveMotionFunc(onMouseMove);
    glutSpecialFunc(onSpecialKeyDown);
    glutDisplayFunc(render);
    glutTimerFunc(30, timer, 0);
}

/**
 *
 * @param drawable
 */
void MainWindow::addDrawable(Drawable* drawable) {
    while (drawables.size() < drawable->getZ() + 1) {
        drawables.push_back(std::vector<Drawable*>());
    }

    drawables[drawable->getZ()].push_back(drawable);
}

/**
 *
 */
void MainWindow::updateDrawables() {
    std::vector<std::vector<Drawable*>> newDrawables = drawables;
    drawables = std::vector<std::vector<Drawable*>>();

    for (std::vector<Drawable*> drawablesForZ : newDrawables) {
        for (Drawable* drawable : drawablesForZ) {
            addDrawable(drawable);
        }
    }
    render();
    update();
}
/**
 *
 * @param clickable
 */
void MainWindow::addClickable(Clickable* clickable) {
    while (clickables.size() < clickable->getClickPriority() + 1) {
        clickables.push_back(std::vector<Clickable*>());
    }
    clickables[clickable->getClickPriority()].push_back(clickable);
}

/**
 *
 */
void MainWindow::update() {
    glutPostRedisplay();
}

/**
 *
 * @param width
 * @param height
 */
void MainWindow::onResize(int width, int height) {
    MainWindow::width = width;
    MainWindow::height = height;
    glutPostRedisplay();
    std::cout << width << ", " << height << std::endl;
}

/**
 *
 * @param button
 * @param state
 * @param x
 * @param y
 */
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

/**
 *
 * @param x
 * @param y
 */
void MainWindow::onMouseMove(int x, int y) {
    mouseX = x;
    mouseY = y;
    eventHandler.fire(Event::MOUSE_MOVE);
}

void MainWindow::timer(int extra) {
    eventHandler.fire(Event::ANIMATE);
    update();
    glutTimerFunc(30, timer, 0);
}

/**
 *
 * @param key
 * @param x
 * @param y
 */
void MainWindow::onSpecialKeyDown(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:
            eventHandler.fire(Event::KEY_DOWN);
            break;
        case GLUT_KEY_LEFT:
            eventHandler.fire(Event::KEY_LEFT);
            break;
        case GLUT_KEY_RIGHT:
            eventHandler.fire(Event::KEY_RIGHT);
            break;
        case GLUT_KEY_UP:
            eventHandler.fire(Event::KEY_UP);
            break;
        case GLUT_KEY_F2:
            eventHandler.fire(Event::KEY_F2);
            break;
    }
}

/**
 *
 */
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

    glutSwapBuffers();

}

/**
 * Getter for eventHandler
 * @return eventHandler
 */
EventHandler& MainWindow::getEventListener() {
    return eventHandler;
}

/**
 * Getter for mouseX
 * @return mouseX
 */
int MainWindow::getMouseX() {
    return mouseX;
}

/**
 * Getter for MouseY
 * @return mouseY
 */
int MainWindow::getMouseY() {
    return mouseY;
}

