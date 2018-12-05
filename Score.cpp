
#include "Score.h"
#include <string>

Score::Score(int x, int y): Drawable(x, y, 10) {

}

void Score::draw(int width, int height) {
    Drawable::draw(width, height);
    string message = "Score:";
    glColor3f(1, 1, 1);
    glRasterPos2i(x, y);
    for (int i = 0; i < message.length(); ++ i) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, message[i]);
    }

}

