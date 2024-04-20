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
    uint16_t x, y;
    uint8_t power, initiative;
    World* world;
    Organism(uint16_t x, uint16_t y, uint8_t power, uint8_t initiative, World* world);
    ~Organism();

public:
    void updatePosition(direction dir);
    virtual void action(World& world) = 0;
    virtual void collision(World& world) = 0;

    World* getWorld() const;
    uint16_t getX() const;
    uint16_t getY() const;
    uint8_t getPower() const;
    uint8_t getInitiative() const;
    virtual uint8_t getSign() const;
};

#endif //VIRTUAL_WORLD_SIMULATION_ORGANISM_H
