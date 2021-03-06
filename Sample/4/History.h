#ifndef SFMLSET_HISTORY_H
#define SFMLSET_HISTORY_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
#include "ObjectState.h"
#include "SnapShot.h"
#include "Stacks.h"


class History {
public:
    History();
    static void pushHistory(const SnapShot& snapshot);
    static SnapShot topHistory();
    static void popHistory();

    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    bool isEmpty();

private:
    static Stacks<SnapShot> stack;
};


#endif //MAIN_CPP_HISTORY_H