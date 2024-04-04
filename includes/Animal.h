//
// Created by varev on 04.04.2024.
//

#ifndef VIRTUAL_WORLD_SIMULATION_ANIMAL_H
#define VIRTUAL_WORLD_SIMULATION_ANIMAL_H

#include <cinttypes>
#include "World.h"

class Animal {
protected:
    uint16_t x, y;
    uint8_t power, initiative;
    Animal(uint16_t x, uint16_t y, uint8_t power, uint8_t initiative);
    ~Animal();

public:
    void updatePosition(uint16_t x, uint16_t y);
    virtual void action(World& world) = 0;
    virtual void collision(World& world) = 0;
};

#endif //VIRTUAL_WORLD_SIMULATION_ANIMAL_H
