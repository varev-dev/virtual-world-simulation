//
// Created by varev on 22.04.2024.
//

#include "../../include/animal/Fox.h"

char Fox::ID = Animal::DERIVED++;

Fox::Fox(uint16_t x, uint16_t y, World *world) : Animal(x, y, world) {
    sign = 'F';
    power = 3;
    initiative = 7;
    name = "Lis";
}

Fox::Fox(uint16_t x, uint16_t y, uint8_t power, uint16_t initiative, World *world)
        : Animal(x, y, power, initiative, world) {
    sign = 'F';
    this->initiative = 7;
    name = "Lis";
}

void Fox::collision(Organism &organism) {
    if (dynamic_cast<Fox*>(&organism)) {
        Animal::birth();
        return;
    }
    Animal::collision(organism);
}

void Fox::action(bool canBeOccupied, bool dodgeStronger) {
    Animal::action(canBeOccupied, dodgeStronger);
}

bool Fox::birth(uint16_t x, uint16_t y) {
    world->addOrganism(*(new Fox(x, y, world)));
    return true;
}
