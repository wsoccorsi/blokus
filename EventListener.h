#ifndef BLOKUS_EVENTLISTENER_H
#define BLOKUS_EVENTLISTENER_H

#import <vector>
#import <unordered_map>

class EventListener {
public:
    enum ReturnType {
        CONTINUE,
        POP
    };

    EventListener();

    virtual unsigned long on(int event, std::function<int()> callback);
    virtual void pop(int event, int id);
    virtual void fire(int event);

protected:
    std::unordered_map<int, std::unordered_map<int, std::function<int()>>> callbacks;
};


#endif //BLOKUS_EVENTLISTENER_H
