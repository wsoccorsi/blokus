//
// Created by Sam Clark on 11/11/18.
//

#ifndef BLOKUS_EVENTLISTENER_H
#define BLOKUS_EVENTLISTENER_H

#include <iostream>
#include <unordered_map>

template <typename EventClass>
class EventListener {
public:
    EventListener();

    unsigned long on(typename EventClass::Event event, std::function<void()> callback);
    void pop(typename EventClass::Event event, unsigned long id);
    void fire(typename EventClass::Event event);

private:
    std::unordered_map<typename EventClass::Event, std::unordered_map<unsigned long, std::function<void()>>> callbacks;
    unsigned long nextId = 0;
};

template <typename EventClass>
EventListener<EventClass>::EventListener() {
    callbacks = std::unordered_map<typename EventClass::Event, std::unordered_map<unsigned long, std::function<void()>>>();
}

template<typename EventClass>
unsigned long EventListener<EventClass>::on(typename EventClass::Event event, std::function<void()> callback) {
    unsigned long callbackId = nextId;
    callbacks[event][callbackId] = callback;
    nextId++;
    return callbackId;
}

template<typename EventClass>
void EventListener<EventClass>::pop(typename EventClass::Event event, unsigned long id) {
    callbacks[event].erase(id);
}

template<typename EventClass>
void EventListener<EventClass>::fire(typename EventClass::Event event) {
    for (std::pair<int, std::function<void()>> callbackPair : callbacks[event]) {
        std::function<void()> callback = callbackPair.second;
        callback();
    }
}

#endif //BLOKUS_EVENTLISTENER_H
