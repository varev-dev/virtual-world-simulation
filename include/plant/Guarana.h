//
// Created by varev on 20.04.2024.
//

#ifndef VIRTUAL_WORLD_SIMULATION_GUARANA_H
#define VIRTUAL_WORLD_SIMULATION_GUARANA_H

#include "../Plant.h"

class Guarana : public Plant {
private:
    static uint8_t STRENGTH_INCREASE;
public:
    Guarana(uint16_t x, uint16_t y, World *world);
    void collision(Organism& organism) override;
    void grow(uint16_t x, uint16_t y) override;
    static char ID;
};

#endif //VIRTUAL_WORLD_SIMULATION_GUARANA_H