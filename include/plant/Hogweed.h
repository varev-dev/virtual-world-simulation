//
// Created by varev on 20.04.2024.
//

#ifndef VIRTUAL_WORLD_SIMULATION_HOGWEED_H
#define VIRTUAL_WORLD_SIMULATION_HOGWEED_H

#include "../Plant.h"

class Hogweed : public Plant {
public:
    uint8_t getSign() override;
    void action() override;
    void collision(Organism& organism) override;
};

#endif //VIRTUAL_WORLD_SIMULATION_HOGWEED_H
