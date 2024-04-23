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
    int32_t lastActionTurn = -1;
public:
    static int32_t JUST_BORN;
    static int32_t FREE;
    Animal(uint16_t x, uint16_t y, World* world);
    void action(bool canBeOccupied = true) override;
    void collision(Organism& organism) override;
    bool birth();
    int32_t getLastActionTurn() const;
    void setLastActionTurn(int32_t turn);
    void setLastActionTurn();
    static Organism* createRandom(uint16_t x, uint16_t y, World& world);
};

#endif //VIRTUAL_WORLD_SIMULATION_ANIMAL_H
