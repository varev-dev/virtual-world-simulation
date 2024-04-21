//
// Created by varev on 18.04.2024.
//

#ifndef VIRTUAL_WORLD_SIMULATION_PLANT_H
#define VIRTUAL_WORLD_SIMULATION_PLANT_H

#include "Organism.h"

class Plant : public Organism {
public:
    Plant(uint16_t x, uint16_t y, uint8_t power, uint8_t initiative, World* world);
    void action() override;
    void collision(Organism& organism) override;
};

#endif //VIRTUAL_WORLD_SIMULATION_PLANT_H
