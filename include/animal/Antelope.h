//
// Created by varev on 23.04.2024.
//

#ifndef VIRTUAL_WORLD_SIMULATION_ANTELOPE_H
#define VIRTUAL_WORLD_SIMULATION_ANTELOPE_H

#include "../Animal.h"

class Antelope : public Animal {
public:
    Antelope(uint16_t x, uint16_t y, World *world);

    Antelope(uint16_t x, uint16_t y, uint8_t power, uint8_t initiative, World *world);

    void action(bool canBeOccupied, bool dodgeStronger) override;
    void collision(Organism &organism) override;

    static char ID;
};

#endif //VIRTUAL_WORLD_SIMULATION_ANTELOPE_H
