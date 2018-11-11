//
// Created by Sam Clark on 11/11/18.
//

#ifndef BLOKUS_EVENTLISTENER_H
#define BLOKUS_EVENTLISTENER_H

#include <iostream>

template <typename T>
class EventListener {
public:
    EventListener();
};

template <typename T>
EventListener<T>::EventListener() {
    std::cout << T::TEST2 << std::endl;
}

#endif //BLOKUS_EVENTLISTENER_H
