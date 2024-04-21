//#pragma once
#include <iostream>
#include "include/World.h"
#include "include/Plant.h"
#include "include/Animal.h"

int main() {
    auto* world = new World(2, 2);
    auto* animal = new Animal(1, 1, 2, 3, world);
    auto* plant = new Plant(2, 1, 1, 0, world);
    world->addOrganism(*animal);
    world->addOrganism(*plant);
    world->printWorld();
    plant->collision(*animal);
    world->printWorld();
    return 0;
}
