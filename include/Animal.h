//
// Created by varev on 04.04.2024.
//

#ifndef VIRTUAL_WORLD_SIMULATION_ANIMAL_H
#define VIRTUAL_WORLD_SIMULATION_ANIMAL_H

#include "Organism.h"
#include "Plant.h"

class Animal : public Organism {
private:
    int32_t lastActionTurn = -1;
public:
    static int32_t JUST_BORN;
    static int32_t FREE;
    Animal(uint16_t x, uint16_t y, World* world);
    void action() override;
    void collision(Organism& organism) override;
    bool birth();
    int32_t getLastActionTurn() const;
    void setLastActionTurn(int32_t turn);
    void setLastActionTurn();
};

#endif //VIRTUAL_WORLD_SIMULATION_ANIMAL_H
