#include <string>
#include "EventHandler.h"

EventHandler::EventHandler() {
    this->callbacks = std::unordered_map<int, std::unordered_map<int, std::function<int()>>>();
}

unsigned long EventHandler::on(int event, std::function<int()> callback) {
    unsigned long callbackId = callbacks[event].size();
    callbacks[event][callbackId] = callback;
    return callbackId;
}

void EventHandler::pop(int event, int id) {
    callbacks[event].erase(id);
}

void EventHandler::fire(int event) {
    for (std::pair<int, std::function<int()>> callback_pair : callbacks[event]) {
        std::function<int()> callback = callback_pair.second;
        ReturnType ret = static_cast<ReturnType>(callback());
        if (ret == ReturnType::POP) {
            pop(event, callback_pair.first);
        }
    }
}
