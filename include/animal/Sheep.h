//
// Created by varev on 22.04.2024.
//

#ifndef VIRTUAL_WORLD_SIMULATION_SHEEP_H
#define VIRTUAL_WORLD_SIMULATION_SHEEP_H

#include "../Animal.h"

class Sheep : public Animal {
public:
    Sheep(uint16_t x, uint16_t y, World* world);
    Sheep(uint16_t x, uint16_t y, uint8_t power, uint16_t action, World* world);

    bool birth(uint16_t x, uint16_t y) override;
    void collision(Organism &organism) override;

    static char ID;
};

#endif //VIRTUAL_WORLD_SIMULATION_SHEEP_H
