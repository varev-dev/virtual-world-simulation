//
// Created by varev on 18.04.2024.
//

#ifndef VIRTUAL_WORLD_SIMULATION_PLANT_H
#define VIRTUAL_WORLD_SIMULATION_PLANT_H

#include "Organism.h"

class Plant : Organism {
public:
    virtual void action(World &world) override;
    virtual void collision(World &world) override;
};

#endif //VIRTUAL_WORLD_SIMULATION_PLANT_H
