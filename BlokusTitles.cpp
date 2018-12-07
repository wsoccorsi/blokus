#include <string>
#include "BlokusTitles.h"

BlokusTitles::BlokusTitles() {

}

void BlokusTitles::draw(int width, int height) {
    Drawable::draw(width, height);
    std::string title = "BLOKUS";
    glColor3f(1,1,1);
    glRasterPos2i(10,30);
    for (int i = 0; i < title.length(); ++ i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, title[i]);
    }
    glColor3f(0,0,0);
    glRasterPos2i(11,31);
    for (int i = 0; i < title.length(); ++ i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, title[i]);
    }

    std::string helpText = "For Game Instructions press (F2)";
    glColor3f(1,1,1);
    glRasterPos2i(649,549);
    for (int i = 0; i < helpText.length(); ++ i) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, helpText[i]);
    }
    glColor3f(0,0,0);
    glRasterPos2i(650,550);
    for (int i = 0; i < helpText.length(); ++ i) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, helpText[i]);
    }
}
