//
// Created by varev on 22.04.2024.
//

#ifndef VIRTUAL_WORLD_SIMULATION_WOLF_H
#define VIRTUAL_WORLD_SIMULATION_WOLF_H

#include "../Animal.h"

class Wolf : public Animal {
public:
    Wolf(uint16_t x, uint16_t y, World* world);
    void collision(Organism &organism) override;
};

#endif //VIRTUAL_WORLD_SIMULATION_WOLF_H
