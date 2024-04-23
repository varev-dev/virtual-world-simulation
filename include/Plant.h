//
// Created by varev on 18.04.2024.
//

#ifndef VIRTUAL_WORLD_SIMULATION_PLANT_H
#define VIRTUAL_WORLD_SIMULATION_PLANT_H

#include "Organism.h"

class Plant : public Organism {
protected:
    uint8_t sowChance = 3; // higher - smaller chance to sow
public:
    Plant(uint16_t x, uint16_t y, World* world);
    static Organism* createRandom(uint16_t x, uint16_t y, World& world);
    void action(bool canBeOccupied = false, bool dodgeStronger = false) override;
    void collision(Organism& organism) override;

    static char DERIVED;
};

#endif //VIRTUAL_WORLD_SIMULATION_PLANT_H
