#ifndef BLOKUS_EVENTHANDLER_H
#define BLOKUS_EVENTHANDLER_H

#import <vector>
#import <unordered_map>

class EventHandler {
public:
    enum ReturnType {
        CONTINUE,
        POP
    };

    EventHandler();

    virtual unsigned long on(int event, std::function<int()> callback);
    virtual void pop(int event, int id);
    virtual void fire(int event);

protected:
    std::unordered_map<int, std::unordered_map<int, std::function<int()>>> callbacks;
};


#endif //BLOKUS_EVENTHANDLER_H
