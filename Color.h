#ifndef BLOKUS_COLOR_H
#define BLOKUS_COLOR_H


class Color {
public:
    Color();
    Color(float r, float g, float b);

    float getR() const;

    void setR(float r);

    float getG() const;

    void setG(float g);

    float getB() const;

    void setB(float b);

private:
    float r;
    float g;
    float b;
};


#endif //BLOKUS_COLOR_H
