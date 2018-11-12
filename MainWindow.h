#ifndef BLOKUS_WINDOW_H
#define BLOKUS_WINDOW_H

#include <string>
#include <vector>
#include <unordered_map>
#include "Drawable.h"
#include "Clickable.h"

class MainWindow {
public:
    explicit MainWindow(std::string title, int width=400, int height=500);

    static void addDrawable(Drawable* drawable);
    static void addClickable(Clickable* clickable);

    static void update();

protected:
    static std::string title;
    static int width;
    static int height;

    static std::vector<std::vector<Drawable*>> drawables; // z index : drawables
    static std::vector<Clickable*> clickables;

    static void render();
    static void onResize(int width, int height);
    static void onClick(int button, int state, int x, int y);
    static void onMouseMove(int x, int y);

};


#endif //BLOKUS_WINDOW_H
