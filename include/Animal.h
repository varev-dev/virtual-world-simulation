//
// Created by varev on 04.04.2024.
//

#ifndef VIRTUAL_WORLD_SIMULATION_ANIMAL_H
#define VIRTUAL_WORLD_SIMULATION_ANIMAL_H

#include "Organism.h"

class Animal : Organism {
public:
    virtual void action(World &world) override;
    virtual void collision(World &world) override;
};

#endif //VIRTUAL_WORLD_SIMULATION_ANIMAL_H
