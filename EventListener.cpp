#include <string>
#include "EventListener.h"

EventListener::EventListener() {
    this->callbacks = std::unordered_map<int, std::unordered_map<int, std::function<int()>>>();
}

unsigned long EventListener::on(int event, std::function<int()> callback) {
    unsigned long callbackId = callbacks[event].size();
    callbacks[event][callbackId] = callback;
    return callbackId;
}

void EventListener::pop(int event, int id) {
    callbacks[event].erase(id);
}

void EventListener::fire(int event) {
    for (std::pair<int, std::function<int()>> callback_pair : callbacks[event]) {
        std::function<int()> callback = callback_pair.second;
        ReturnType ret = static_cast<ReturnType>(callback());
        if (ret == ReturnType::POP) {
            pop(event, callback_pair.first);
        }
    }
}
