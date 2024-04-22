//
// Created by varev on 21.04.2024.
//

#include <iostream>
#include <random>
#include "../include/Plant.h"
#include "../include/exception/PositionException.h"

Plant::Plant(uint16_t x, uint16_t y, World *world) :
        Organism(x, y, 0, 0, world) {
    Organism::sign = 'P';
};

void Plant::collision(Organism &organism) {
    world->removeOrganism(*this);
    auto* position = new uint16_t[2]{x, y};
    organism.updatePosition(position);
    delete[] position;
}

void Plant::action() {
    bool checked[4] = {false,false,false,false};
    while (!Organism::isEveryDirectionChecked(checked)) {
        direction random;
        try { random = getRandomDirection(); }
        catch (const PositionException& e) { break; }

        if (checked[random]) continue;

        checked[random] = true;
        uint16_t* position = newPosition(random);

        if (world->getOrganismByPosition(position[X], position[Y]) != nullptr)
            continue;

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 3);

        if (dis(gen) == 0)
            world->growPlant(*this, position);

        delete[] position;
        break;
    }
}

