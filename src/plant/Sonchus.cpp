//
// Created by varev on 21.04.2024.
//

#include "../../include/plant/Sonchus.h"

uint8_t Sonchus::SPREAD_ATTEMPTS = 3;

Sonchus::Sonchus(uint16_t x, uint16_t y, World *world) :
        Plant(x, y, world) {
    sign = 'S';
    sowChance = 5;
}

void Sonchus::action() {
    for (int i = 0; i < SPREAD_ATTEMPTS; i++) {
        Plant::action();
    }
}
