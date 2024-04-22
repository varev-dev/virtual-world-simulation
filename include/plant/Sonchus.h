//
// Created by varev on 20.04.2024.
//

#ifndef VIRTUAL_WORLD_SIMULATION_SONCHUS_H
#define VIRTUAL_WORLD_SIMULATION_SONCHUS_H

#include "../Plant.h"

// Mlecz
class Sonchus : public Plant {
private:
    static uint8_t SPREAD_ATTEMPTS;
public:
    Sonchus(uint16_t x, uint16_t y, World *world);
    void action() override;
};

#endif //VIRTUAL_WORLD_SIMULATION_SONCHUS_H
