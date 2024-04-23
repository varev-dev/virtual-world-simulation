//
// Created by varev on 04.04.2024.
//

#ifndef VIRTUAL_WORLD_SIMULATION_HUMAN_H
#define VIRTUAL_WORLD_SIMULATION_HUMAN_H

#include "Animal.h"

class Human : public Animal {
protected:
    int option;
public:
    static uint8_t SKILL_DELAY;
    static uint8_t SKILL_DURATION;

    Human(uint16_t x, uint16_t y, World* world);
    Human(uint16_t x, uint16_t y, uint8_t power, uint16_t skill, World* world);

    void action(bool canBeOccupied, bool dodgeStronger) override;
    void collision(Organism &organism) override;
    void setOption(int option);
};

#endif //VIRTUAL_WORLD_SIMULATION_HUMAN_H
