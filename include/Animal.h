//
// Created by varev on 04.04.2024.
//

#ifndef VIRTUAL_WORLD_SIMULATION_ANIMAL_H
#define VIRTUAL_WORLD_SIMULATION_ANIMAL_H

#include "Organism.h"
#include "Plant.h"

class Animal : public Organism {
public:
    virtual void action() override;
    virtual void collision(Organism& organism) override;
};

#endif //VIRTUAL_WORLD_SIMULATION_ANIMAL_H
