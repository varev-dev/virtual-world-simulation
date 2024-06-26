//
// Created by varev on 22.04.2024.
//

#include "../../include/animal/Wolf.h"

char Wolf::ID = Animal::DERIVED++;

Wolf::Wolf(uint16_t x, uint16_t y, World *world) : Animal(x, y, world) {
    sign = 'W';
    power = 9;
    initiative = 5;
    name = "Wilk";
}

Wolf::Wolf(uint16_t x, uint16_t y, uint8_t power, uint16_t initiative, World *world)
        : Animal(x, y, power, initiative, world) {
    sign = 'W';
    this->initiative = 5;
    name = "Wilk";
}

void Wolf::collision(Organism &organism) {
    if (dynamic_cast<Wolf*>(&organism)) {
        Animal::birth();
        return;
    }
    Animal::collision(organism);
}

bool Wolf::birth(uint16_t x, uint16_t y) {
    world->addOrganism(*(new Wolf(x, y, world)));
    return true;
}
