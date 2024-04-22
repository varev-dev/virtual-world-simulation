//#pragma once
#include <iostream>
#include <unistd.h>
#include "include/World.h"
#include "include/Animal.h"
#include "include/plant/Guarana.h"
#include "include/plant/Hogweed.h"
#include "include/animal/Fox.h"
#include "include/animal/Wolf.h"

int main() {
    auto* world = new World(1,2);
    auto* animal = new Fox(0, 1, world);
    auto* animal2 = new Wolf(0, 0, world);
    //auto* plant = new Hogweed(2, 0, world);

    world->addOrganism(*animal);
    world->addOrganism(*animal2);

    while (true) {
        world->printWorld();
        world->makeTurn();
        usleep(500000);
    }

    return 0;
}
