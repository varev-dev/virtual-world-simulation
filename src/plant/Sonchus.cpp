//
// Created by varev on 21.04.2024.
//

#include "../../include/plant/Sonchus.h"

Sonchus::Sonchus(uint16_t x, uint16_t y, World *world) :
        Plant(x, y, world) {
    sign = 'S';
    power = 5;
}

void Sonchus::action() {
    Plant::action();
}
