#ifndef BLOKUS_CLICKABLE_H
#define BLOKUS_CLICKABLE_H


class Clickable {
public:
    Clickable();

    virtual void onClick(int x, int y);
    virtual void isInBounds(int x, int y);
};


#endif //BLOKUS_CLICKABLE_H
