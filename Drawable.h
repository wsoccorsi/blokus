#ifndef BLOKUS_DRAWABLE_H
#define BLOKUS_DRAWABLE_H

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


class Drawable {
public:
    Drawable();
    Drawable(int x, int y, int z);
    virtual void draw(int width, int height);

    int getX() const;
    void setX(int x);

    int getY() const;
    void setY(int y);

    int getZ() const;
    void setZ(int z);

protected:
    int x;
    int y;
    int z;
};


#endif //BLOKUS_DRAWABLE_H
