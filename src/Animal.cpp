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
    bool checked[4] = {false, false, false, false};
    while (!Organism::isEveryDirectionChecked(checked)) {
        direction dir = getRandomDirection();

        if (checked[dir]) continue;
        checked[dir] = true;

        uint16_t* position = newPosition(dir);

        if (position[X] == x && position[Y] == y)
            continue;

        Organism* collider = world->getOrganismByPosition(position[X], position[Y]);

        if (collider) collider->collision(*this);
        else updatePosition(position);

        delete[] position;
        break;
    }
}

void Animal::collision(Organism &organism) {
    if (power <= organism.getPower())
        world->removeOrganism(*this);
    else
        world->removeOrganism(organism);
}
