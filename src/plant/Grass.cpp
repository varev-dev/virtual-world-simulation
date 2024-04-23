//
// Created by varev on 21.04.2024.
//

#include "../../include/plant/Grass.h"

char Grass::ID = Plant::DERIVED++;

Grass::Grass(uint16_t x, uint16_t y, World *world) :
        Plant(x, y, world) {
    sign = 't';
    name = "Trawa";
}

void Grass::grow(uint16_t x, uint16_t y) {
    world->addOrganism(*(new Grass(x, y, world)));
}

