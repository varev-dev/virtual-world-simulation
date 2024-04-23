//
// Created by varev on 18.04.2024.
//

#ifndef VIRTUAL_WORLD_SIMULATION_ORGANISM_H
#define VIRTUAL_WORLD_SIMULATION_ORGANISM_H

#include <cinttypes>
#include "Direction.h"

#include "World.h"
class World;

class Organism {
protected:
    uint8_t sign = 'U';
    uint16_t x, y;
    uint8_t power, initiative;
    World* world;
    int32_t lastActionTurn = -1;

    Organism(uint16_t x, uint16_t y, uint8_t power, uint16_t initiative, World* world);
    ~Organism();
    static direction getRandomDirection();
    static bool isEveryDirectionChecked(const bool* directions);

public:
    virtual void action(bool canBeOccupied, bool dodgeStronger) = 0;
    virtual void collision(Organism& organism) = 0;
    virtual uint8_t getSign();

    int32_t getLastActionTurn() const;
    void setLastActionTurn(int32_t turn);
    void setLastActionTurn();
    uint16_t getX() const;
    uint16_t getY() const;
    uint8_t getPower() const;
    uint8_t getInitiative() const;
    void setPower(uint8_t power);
    void updatePosition(const uint16_t position[2]);
    uint16_t* newPosition(direction dir);

    friend std::ofstream& operator<<(std::ofstream& os, const Organism& organism);

    static int32_t JUST_BORN;
    static int32_t FREE;
};

#endif //VIRTUAL_WORLD_SIMULATION_ORGANISM_H
