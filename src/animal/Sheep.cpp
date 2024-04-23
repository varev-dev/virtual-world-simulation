//
// Created by varev on 22.04.2024.
//

#include "../../include/animal/Sheep.h"

char Sheep::ID = Animal::DERIVED++;

Sheep::Sheep(uint16_t x, uint16_t y, World *world) : Animal(x, y, world) {
    sign = 'P';
    power = 4;
    initiative = 4;
    name = "Owca";
}

Sheep::Sheep(uint16_t x, uint16_t y, uint8_t power, uint16_t initiative, World *world)
        : Animal(x, y, power, initiative, world) {
    sign = 'P';
    this->initiative = 4;
    name = "Owca";
}

void Sheep::collision(Organism &organism) {
    if (dynamic_cast<Sheep*>(&organism)) {
        Animal::birth();
        return;
    }
    Animal::collision(organism);
}

bool Sheep::birth(uint16_t x, uint16_t y) {
    world->addOrganism(*(new Sheep(x, y, world)));
    return true;
}
