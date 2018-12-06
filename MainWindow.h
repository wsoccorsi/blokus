#ifndef BLOKUS_WINDOW_H
#define BLOKUS_WINDOW_H

#include <string>
#include <vector>
#include <unordered_map>
#include "Drawable.h"
#include "Clickable.h"
#include "EventHandler.h"

class MainWindow: public EventHandler {
public:
    enum Event {
        MOUSE_MOVE,
        MOUSE_CLICK,
        KEY_DOWN,
        KEY_LEFT,
        KEY_UP,
        KEY_RIGHT,
        KEY_F2,
        ANIMATE
    };

    explicit MainWindow(std::string title, int width=500, int height=500);

    static void addDrawable(Drawable* drawable);
    static void updateDrawables();

    static void addClickable(Clickable* clickable);

    static void update();
    static void render();

    static EventHandler& getEventListener();

    static int getMouseX();
    static int getMouseY();

protected:
    static std::string title;
    static int width;
    static int height;

    static int mouseX;
    static int mouseY;

    static EventHandler eventHandler;

    static std::vector<std::vector<Drawable*>> drawables; // z index : drawables
    static std::vector<std::vector<Clickable*>> clickables;

    static bool animating;

    static void onResize(int width, int height);
    static void onClick(int button, int state, int x, int y);
    static void onSpecialKeyDown(int key, int x, int y);
    static void onMouseMove(int x, int y);
    static void timer(int extra);

};


#endif //BLOKUS_WINDOW_H
