//
// Created by varev on 18.04.2024.
//

#ifndef VIRTUAL_WORLD_SIMULATION_ORGANISM_H
#define VIRTUAL_WORLD_SIMULATION_ORGANISM_H

#include "World.h"
#include <cinttypes>

class World;
class Organism {
protected:
    uint16_t x, y;
    uint8_t power, initiative;
    Organism(uint16_t x, uint16_t y, uint8_t power, uint8_t initiative);
    ~Organism();

public:
    void updatePosition(uint16_t x, uint16_t y);
    virtual void action(World& world) = 0;
    virtual void collision(World& world) = 0;
};

#endif //VIRTUAL_WORLD_SIMULATION_ORGANISM_H
