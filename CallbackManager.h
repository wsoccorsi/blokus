#ifndef BLOKUS_CALLBACKMANAGER_H
#define BLOKUS_CALLBACKMANAGER_H

#import <vector>
#import <unordered_map>

class CallbackManager {
public:
    CallbackManager();

    unsigned long on(std::string event, std::function<void()> callback);
    void pop(std::string event, int id);
    void fire(std::string event);

protected:
    std::unordered_map<std::string, std::unordered_map<int, std::function<void()>>> callbacks;
};


#endif //BLOKUS_CALLBACKMANAGER_H
