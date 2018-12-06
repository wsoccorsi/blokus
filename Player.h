#ifndef BLOKUS_PLAYER_H
#define BLOKUS_PLAYER_H

#include "Piece.h"
#include "Tray.h"
#include "Board.h"

class Blokus;

class Player {

public:
    explicit Player(Blokus* blokus, Color color, std::string title, Coordinate trayCoord, Board* board);

    struct PossibleMove {
        PossibleMove() {
            this->piece = nullptr;
            this->position = Coordinate();
            this->rotation = 0;
            this->score = 0;
        }
        PossibleMove(Piece* piece, Coordinate position, int rotation) {
            this->piece = piece;
            this->position = position;
            this->rotation = rotation;
            this->score = 0;
        }
        Piece* piece;
        Coordinate position;
        int rotation;
        int score;
    };

    std::vector<PossibleMove> getPossibleMoves();

    virtual const Color &getColor() const;
    virtual void setColor(const Color &color);
    virtual const std::string &getTitle() const;
    virtual void setTitle(const std::string &title);
    virtual Tray *getTray() const;
    virtual void setTray(Tray *tray);

protected:
    Blokus* blokus;
    Color color;
    std::string title;
    Board* board;

    Tray* tray;

};


#endif //BLOKUS_PLAYER_H
