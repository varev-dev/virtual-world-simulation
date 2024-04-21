//
// Created by varev on 04.04.2024.
//

#ifndef VIRTUAL_WORLD_SIMULATION_ANIMAL_H
#define VIRTUAL_WORLD_SIMULATION_ANIMAL_H

#include "Organism.h"
#include "Plant.h"

class Animal : public Organism {
private:
    uint32_t lastActionTurn = 0;
public:
    Animal(uint16_t x, uint16_t y, uint8_t power, uint8_t initiative, World* world);
    void action() override;
    void collision(Organism& organism) override;
};

#endif //VIRTUAL_WORLD_SIMULATION_ANIMAL_H
