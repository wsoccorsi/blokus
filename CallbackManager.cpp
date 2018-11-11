#include <string>
#include "CallbackManager.h"

CallbackManager::CallbackManager() {
    this->callbacks = std::unordered_map<std::string, std::unordered_map<int, std::function<void()>>>();
}

unsigned long CallbackManager::on(std::string event, std::function<void()> callback) {
    unsigned long callbackId = callbacks[event].size();
    callbacks[event][callbackId] = callback;
    return callbackId;
}

void CallbackManager::pop(std::string event, int id) {
    callbacks[event].erase(id);
}

void CallbackManager::fire(std::string event) {
    for (std::pair<int, std::function<void()>> callback_pair : callbacks[event]) {
        std::function<void()> callback = callback_pair.second;
        callback();
    }
}
