#include "Scoreboard.h"
#include "MainWindow.h"

/**
 * Constructor for scoreboard sets score
 *
 */
Scoreboard::Scoreboard(): Drawable(0, 0, 0) {
    this->score = 0;
}

Scoreboard::Scoreboard(int x, int y): Drawable(x, y, 2) {
    this->score = 0;
}

/**
 * setter for score
 *
 * @param score
 */
void Scoreboard::setScore(int score) {
    this->score = score;
    MainWindow::updateDrawables();
}

/**
 * draws score
 *
 * @param width
 * @param height
 */
void Scoreboard::draw(int width, int height) {
    Drawable::draw(width, height);
    std::string message = "Score: " + std::to_string(this->score);
    glColor3f(0, 0, 0);
    glRasterPos2i(x, y);
    for (int i = 0; i < message.length(); ++ i) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, message[i]);
    }
}

/**
 * getter for score
 *
 * @return
 */
int Scoreboard::getScore() const {
    return score;
}
