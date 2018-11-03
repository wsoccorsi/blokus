#ifndef BLOKUS_WINDOW_H
#define BLOKUS_WINDOW_H

#include <string>
#include <vector>
#include <unordered_map>
#include "Drawable.h"

class MainWindow {
public:
    explicit MainWindow(std::string title, int width=400, int height=500);

    static void addDrawable(Drawable* drawable);

private:
    static std::string title;
    static int width;
    static int height;

    static std::vector<std::vector<Drawable*>> drawables; // z index : drawables

    static void render();
    static void onResize(int width, int height);

};


#endif //BLOKUS_WINDOW_H
