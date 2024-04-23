//#pragma once
#include <iostream>
#include <unistd.h>
#include "include/World.h"

int main() {
    uint16_t width = 0, height = 0;
    std::cout << "Enter width: ";
    std::cin >> width;
    std::cout << "Enter height: ";
    std::cin >> height;
    if (width < 1 || height < 1)
        return 0;

    auto* world = new World(width, height);
    world->initOrganisms();

    while (true) {
        world->printWorld();
        world->makeTurn();
        usleep(500000);
    }

    return 0;
}
