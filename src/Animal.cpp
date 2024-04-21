//
// Created by varev on 04.04.2024.
//

#include "../include/Animal.h"

#include <random>
#include <iostream>

Animal::Animal(uint16_t x, uint16_t y, uint8_t power, uint8_t initiative, World *world) :
        Organism(x, y, power, initiative, world) {
    Organism::sign = 'A';
}

void Animal::action() {
    direction dir = getRandomDirection();
    uint16_t* position = newPosition(dir);

    Organism* collider;

    for (auto org : world->getOrganisms()) {
        if (org->getX() != position[X])
            continue;
        if (org->getY() != position[Y])
            continue;

        collider = org;
    }

    collider->collision(*this);
    delete(position);
}

void Animal::collision(Organism &organism) {
    if (power <= organism.getPower())
        world->removeOrganism(*this);
    else
        world->removeOrganism(organism);
}
