//
// Created by varev on 22.04.2024.
//

#ifndef VIRTUAL_WORLD_SIMULATION_WOLF_H
#define VIRTUAL_WORLD_SIMULATION_WOLF_H

#include "../Animal.h"

class Wolf : public Animal {
public:
    Wolf(uint16_t x, uint16_t y, World* world);
    Wolf(uint16_t x, uint16_t y, uint8_t power, uint16_t action, World* world);

    void collision(Organism &organism) override;

    static char ID;
};

#endif //VIRTUAL_WORLD_SIMULATION_WOLF_H
