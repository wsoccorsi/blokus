#ifndef BLOKUS_WINDOW_H
#define BLOKUS_WINDOW_H

#include <string>

class MainWindow {
public:
    MainWindow(std::string title, int width=400, int height=500);

private:

    static std::string title;
    static int width;
    static int height;

    static void render();
    static void onResize(int width, int height);

};


#endif //BLOKUS_WINDOW_H
