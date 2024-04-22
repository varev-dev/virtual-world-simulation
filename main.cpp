//#pragma once
#include <iostream>
#include <unistd.h>
#include "include/World.h"
#include "include/Animal.h"
#include "include/plant/Guarana.h"
#include "include/plant/Hogweed.h"

int main() {
    auto* world = new World(4,4);
    auto* animal = new Animal(0, 3, 2, 3, world);
    auto* plant = new Hogweed(2, 0, world);

    world->addOrganism(*animal);
    world->addOrganism(*plant);

    world->printWorld();
    usleep(500000);
    while (!world->isWorldFull()) {
        world->makeTurn();
        world->printWorld();
        usleep(500000);
    }

    return 0;
}
