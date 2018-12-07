#ifndef BLOKUS_PLAYER_H
#define BLOKUS_PLAYER_H

#include "Piece.h"
#include "Tray.h"
#include "Board.h"
#include "Scoreboard.h"

class Blokus;

class Player {

public:
    explicit Player(Blokus* blokus, Color color, Coordinate trayCoord, Board* board, Coordinate start, std::string title);

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
    virtual Tray *getTray() const;
    virtual void setTray(Tray *tray);
    virtual const Coordinate &getStart() const;
    virtual int getScore() const;
    virtual void setScore(int score);
    virtual const std::string &getTitle() const;
    virtual void setTitle(const std::string &title);

protected:
    Blokus* blokus;
    Color color;
    Board* board;
    Coordinate start;
    std::string title;

    Tray* tray;
    Scoreboard* scoreboard;

};


#endif //BLOKUS_PLAYER_H
