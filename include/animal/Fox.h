//
// Created by varev on 22.04.2024.
//

#ifndef VIRTUAL_WORLD_SIMULATION_FOX_H
#define VIRTUAL_WORLD_SIMULATION_FOX_H

#include "../Animal.h"

class Fox : public Animal {
public:
    Fox(uint16_t x, uint16_t y, World *world);
    void collision(Organism &organism) override;
    void action(bool canBeOccupied, bool dodgeStronger) override;

    static char ID;
};

#endif //VIRTUAL_WORLD_SIMULATION_FOX_H
