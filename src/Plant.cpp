//
// Created by varev on 21.04.2024.
//

#include <iostream>
#include <random>
#include "../include/Plant.h"
#include "../include/plant/Grass.h"
#include "../include/plant/Belladonna.h"
#include "../include/plant/Guarana.h"
#include "../include/plant/Sonchus.h"
#include "../include/plant/Hogweed.h"

char Plant::DERIVED = 0;

Plant::Plant(uint16_t x, uint16_t y, World *world) :
        Organism(x, y, 0, 0, world) {
    Organism::sign = 'p';
};

Plant::Plant(uint16_t x, uint16_t y, uint8_t power, uint16_t initiative, World *world)
        : Organism(x, y, power, initiative, world) {
    Organism::sign = 'p';
}

void Plant::collision(Organism &organism) {
    world->removeOrganism(*this);
    auto* position = new uint16_t[2]{x, y};
    organism.updatePosition(position);
    delete[] position;
}

void Plant::action(bool canBeOccupied, bool dodgeStronger) {
    bool checked[4] = {false,false,false,false};
    while (!Organism::isEveryDirectionChecked(checked)) {
        direction random = getRandomDirection();

        if (checked[random]) continue;

        checked[random] = true;
        uint16_t* position = newPosition(random);

        if (!world->isPositionLegal(position[X], position[Y]))
            continue;

        if (world->getOrganismByPosition(position[X], position[Y]) != nullptr)
            continue;

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 7);

        if (dis(gen) == 0)
            world->growPlant(*this, position);

        delete[] position;
        break;
    }
}

Organism *Plant::createRandom(uint16_t x, uint16_t y, World& world) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, DERIVED - 1);

    int random = dis(gen);

    if (random == Grass::ID)
        return new Grass(x, y, &world);
    else if (random == Belladonna::ID)
        return new Belladonna(x, y, &world);
    else if (random == Guarana::ID)
        return new Guarana(x, y, &world);
    else if (random == Sonchus::ID)
        return new Sonchus(x, y, &world);
    else if (random == Hogweed::ID)
        return new Hogweed(x, y, &world);
}