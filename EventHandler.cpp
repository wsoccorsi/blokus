#include <string>
#include "EventHandler.h"

/**
 * Constructor for Event Handler
 *
 */
EventHandler::EventHandler() {
    this->callbacks = std::unordered_map<int, std::unordered_map<unsigned long, std::function<int()>>>();
    this->nextId = 0;
}

/**
 *
 *
 * @param event
 * @param callback
 * @return
 */
unsigned long EventHandler::on(int event, std::function<int()> callback) {
    unsigned long callbackId = nextId;
    callbacks[event][callbackId] = callback;
    nextId++;
    return callbackId;
}

/**
 *
 * @param event
 * @param id
 */
void EventHandler::pop(int event, unsigned long id) {
    callbacks[event].erase(id);
}

/**
 *
 * @param event
 */
void EventHandler::fire(int event) {
    std::vector<unsigned long> idsToPop = std::vector<unsigned long>();

    for (std::pair<unsigned long, std::function<int()>> callback_pair : callbacks[event]) {
        std::function<int()> callback = callback_pair.second;
        ReturnType ret = static_cast<ReturnType>(callback());
        if (ret == ReturnType::POP) {
            idsToPop.push_back(callback_pair.first);
        }
    }

    for (unsigned long id : idsToPop) {
        pop(event, id);
    }
}
