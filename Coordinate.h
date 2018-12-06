#ifndef BLOKUS_COORDINATE_H
#define BLOKUS_COORDINATE_H


#include <ostream>

class Coordinate {
public:
    Coordinate();
    Coordinate(int x, int y);

    int getX() const;
    void setX(int x);

    int getY() const;
    void setY(int y);

    Coordinate operator+(const Coordinate& coord) const;

    bool operator==(const Coordinate &rhs) const;

    bool operator!=(const Coordinate &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Coordinate &coordinate);

private:
    int x;
    int y;
};


#endif //BLOKUS_COORDINATE_H
