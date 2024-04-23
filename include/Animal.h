//
// Created by varev on 04.04.2024.
//

#ifndef VIRTUAL_WORLD_SIMULATION_ANIMAL_H
#define VIRTUAL_WORLD_SIMULATION_ANIMAL_H

#include "Organism.h"
#include "Plant.h"

class World;

class Animal : public Organism {
public:
    static char DERIVED;
public:
    Animal(uint16_t x, uint16_t y, World* world);
    Animal(uint16_t x, uint16_t y, uint8_t power, uint16_t action, World *world);

    void action(bool canBeOccupied = true, bool dodgeStronger = false) override;
    void collision(Organism& organism) override;
    bool birth();
    static Organism* createRandom(uint16_t x, uint16_t y, World& world);
};

#endif //VIRTUAL_WORLD_SIMULATION_ANIMAL_H
