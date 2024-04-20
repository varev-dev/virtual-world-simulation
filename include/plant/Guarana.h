//
// Created by varev on 20.04.2024.
//

#ifndef VIRTUAL_WORLD_SIMULATION_GUARANA_H
#define VIRTUAL_WORLD_SIMULATION_GUARANA_H

#include "../Plant.h"

class Guarana : public Plant {
public:
    uint8_t getSign() override;
    void collision(Organism& organism) override;
};

#endif //VIRTUAL_WORLD_SIMULATION_GUARANA_H
