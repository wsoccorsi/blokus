#ifndef BLOKUS_COORDINATE_H
#define BLOKUS_COORDINATE_H


class Coordinate {
public:
    Coordinate();
    Coordinate(int x, int y);

    int getX() const;
    void setX(int x);

    int getY() const;
    void setY(int y);

private:
    int x;
    int y;
};


#endif //BLOKUS_COORDINATE_H
