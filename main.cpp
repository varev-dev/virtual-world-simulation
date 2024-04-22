//#pragma once
#include <iostream>
#include <unistd.h>
#include "include/World.h"
#include "include/Animal.h"
#include "include/plant/Guarana.h"

int main() {
    auto* world = new World(8, 8);
    auto* animal = new Animal(1, 1, 2, 3, world);
    auto* plant = new Guarana(0, 0, world);
    //world->addOrganism(*plant);
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
