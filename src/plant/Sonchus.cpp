//
// Created by varev on 21.04.2024.
//

#include "../../include/plant/Sonchus.h"

char Sonchus::ID = Plant::DERIVED++;
uint8_t Sonchus::SPREAD_ATTEMPTS = 3;

Sonchus::Sonchus(uint16_t x, uint16_t y, World *world) :
        Plant(x, y, world) {
    sign = 's';
    sowChance = 5;
    name = "Mlecz";
}

void Sonchus::action(bool canBeOccupied, bool dodgeStronger) {
    for (int i = 0; i < SPREAD_ATTEMPTS; i++) {
        Plant::action();
    }
}

void Sonchus::grow(uint16_t x, uint16_t y) {
    world->addOrganism(*(new Sonchus(x, y, world)));
}
