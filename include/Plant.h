//
// Created by varev on 18.04.2024.
//

#ifndef VIRTUAL_WORLD_SIMULATION_PLANT_H
#define VIRTUAL_WORLD_SIMULATION_PLANT_H

#include "Organism.h"

class Plant : public Organism {
public:
    virtual uint8_t getSign() override;
    virtual void action() override;
    virtual void collision(Organism& organism) override;
};

#endif //VIRTUAL_WORLD_SIMULATION_PLANT_H
