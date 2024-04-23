//
// Created by varev on 04.04.2024.
//

#ifndef VIRTUAL_WORLD_SIMULATION_ANIMAL_H
#define VIRTUAL_WORLD_SIMULATION_ANIMAL_H

#include "Organism.h"
#include "Plant.h"

class Animal : public Organism {
public:
    static char DERIVED;
public:
    Animal(uint16_t x, uint16_t y, World* world);
    void action(bool canBeOccupied = true) override;
    void collision(Organism& organism) override;
    bool birth();
    static Organism* createRandom(uint16_t x, uint16_t y, World& world);
};

#endif //VIRTUAL_WORLD_SIMULATION_ANIMAL_H
