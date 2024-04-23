//
// Created by varev on 23.04.2024.
//

#ifndef VIRTUAL_WORLD_SIMULATION_ANTELOPE_H
#define VIRTUAL_WORLD_SIMULATION_ANTELOPE_H

#include "../Animal.h"

class Antelope : public Animal {
public:
    Antelope(uint16_t x, uint16_t y, World *world);
    void action(bool canBeOccupied) override;
    void collision(Organism &organism) override;

    static char ID;
};

#endif //VIRTUAL_WORLD_SIMULATION_ANTELOPE_H
