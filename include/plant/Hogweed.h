//
// Created by varev on 20.04.2024.
//

#ifndef VIRTUAL_WORLD_SIMULATION_HOGWEED_H
#define VIRTUAL_WORLD_SIMULATION_HOGWEED_H

#include "../Plant.h"

// Barszcz Sosnowskiego
class Hogweed : public Plant {
public:
    Hogweed(uint16_t x, uint16_t y, World *world);
    void action(bool canBeOccupied) override;
    void collision(Organism& organism) override;
    static char ID;
};

#endif //VIRTUAL_WORLD_SIMULATION_HOGWEED_H
