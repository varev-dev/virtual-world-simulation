//
// Created by varev on 20.04.2024.
//

#ifndef VIRTUAL_WORLD_SIMULATION_GRASS_H
#define VIRTUAL_WORLD_SIMULATION_GRASS_H

#include "../Plant.h"

class Grass : public Plant {
    uint8_t getSign() override;
};

#endif //VIRTUAL_WORLD_SIMULATION_GRASS_H
