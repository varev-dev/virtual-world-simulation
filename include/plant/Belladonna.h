//
// Created by varev on 20.04.2024.
//

#ifndef VIRTUAL_WORLD_SIMULATION_BELLADONNA_H
#define VIRTUAL_WORLD_SIMULATION_BELLADONNA_H

#include "../Plant.h"

// Wilcze Jagody
class Belladonna : public Plant {
public:
    Belladonna(uint16_t x, uint16_t y, World *world);
    void collision(Organism& organism) override;
    void grow(uint16_t x, uint16_t y) override;
    static char ID;
};

#endif //VIRTUAL_WORLD_SIMULATION_BELLADONNA_H
