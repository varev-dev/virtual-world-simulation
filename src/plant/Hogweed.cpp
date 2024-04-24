//
// Created by varev on 21.04.2024.
//

#include "../../include/plant/Hogweed.h"
#include "../../include/Animal.h"

char Hogweed::ID = Plant::DERIVED++;

Hogweed::Hogweed(uint16_t x, uint16_t y, World *world) :
        Plant(x, y, world) {
    power = 10;
    sign = 'h';
    name = "Barszcz sosnowskiego";
}

void Hogweed::action(bool canBeOccupied, bool dodgeStronger) {
    for (int i = 0; i < EAST; i++) {
        uint16_t* pos = newPosition((direction) i);

        if (x == pos[X] && y == pos[Y]) {
            delete[] pos;
            continue;
        }

        Organism* org = world->getOrganismByPosition(pos[X], pos[Y]);
        if (!org) {
            delete[] pos;
            continue;
        }

        if (auto* a = dynamic_cast<Animal*>(org)) {
            world->addMessage(org->getName() + " umiera przez " + name);
            world->removeOrganism(*org);
        }
        delete[] pos;
    }
}

void Hogweed::collision(Organism &organism) {
    world->removeOrganism(organism);
}

void Hogweed::grow(uint16_t x, uint16_t y) {
    world->addOrganism(*(new Hogweed(x, y, world)));
}
