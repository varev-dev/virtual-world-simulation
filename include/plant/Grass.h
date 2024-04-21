//
// Created by varev on 20.04.2024.
//

#ifndef VIRTUAL_WORLD_SIMULATION_GRASS_H
#define VIRTUAL_WORLD_SIMULATION_GRASS_H

#include "../Plant.h"

class Grass : public Plant {
public:
    Grass(uint16_t x, uint16_t y, World *world);
};

#endif //VIRTUAL_WORLD_SIMULATION_GRASS_H
