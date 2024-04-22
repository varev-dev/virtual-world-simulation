//
// Created by varev on 04.04.2024.
//

#ifndef VIRTUAL_WORLD_SIMULATION_ANIMAL_H
#define VIRTUAL_WORLD_SIMULATION_ANIMAL_H

#include "Organism.h"
#include "Plant.h"

class Animal : public Organism {
private:
    uint32_t lastActionTurn = -1;
public:
    static uint32_t JUST_BORN;
    static uint32_t FREE;
    Animal(uint16_t x, uint16_t y, World* world);
    void action() override;
    void collision(Organism& organism) override;
    bool birth();
    uint32_t getLastActionTurn() const;
    void setLastActionTurn(uint32_t turn);
    void setLastActionTurn();
};

#endif //VIRTUAL_WORLD_SIMULATION_ANIMAL_H
