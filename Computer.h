//
// Created by William  Soccorsi on 10/31/18.
//

#ifndef BLOKUS_COMPUTER_H
#define BLOKUS_COMPUTER_H


enum intelligence {SMART, DUMB};

class Computer {

public:

    Computer();

    void computerMove();

    void setInteligence(enum intelligence i);


private:

    intelligence itel;

};


#endif //BLOKUS_COMPUTER_H
