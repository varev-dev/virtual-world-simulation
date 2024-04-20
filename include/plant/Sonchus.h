//
// Created by varev on 20.04.2024.
//

#ifndef VIRTUAL_WORLD_SIMULATION_SONCHUS_H
#define VIRTUAL_WORLD_SIMULATION_SONCHUS_H

#include "../Plant.h"

class Sonchus : public Plant {
public:
    uint8_t getSign() override;
    void action() override;
};

#endif //VIRTUAL_WORLD_SIMULATION_SONCHUS_H
