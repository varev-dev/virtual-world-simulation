//
// Created by varev on 21.04.2024.
//

#include "../../include/plant/Grass.h"

Grass::Grass(uint16_t x, uint16_t y, World *world) :
        Plant(x, y, world) {
    sign = 'T';
}

