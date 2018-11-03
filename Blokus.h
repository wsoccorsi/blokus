#ifndef BLOKUS_BLOKUS_H
#define BLOKUS_BLOKUS_H


#include "MainWindow.h"
#include "Board.h"

class Blokus: public MainWindow {
public:
    explicit Blokus(int width=400, int height=500);

private:
    Board* board;
};


#endif //BLOKUS_BLOKUS_H
