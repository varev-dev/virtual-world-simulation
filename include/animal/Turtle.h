//
// Created by varev on 23.04.2024.
//

#ifndef VIRTUAL_WORLD_SIMULATION_TURTLE_H
#define VIRTUAL_WORLD_SIMULATION_TURTLE_H

#include "../Animal.h"

class Turtle : public Animal {
private:
    static uint8_t MAX_POWER_TO_IGNORE;
public:
    Turtle(uint16_t x, uint16_t y, World *world);
    void collision(Organism &organism) override;
    void action() override;
};

#endif //VIRTUAL_WORLD_SIMULATION_TURTLE_H