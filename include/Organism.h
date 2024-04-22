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
    Organism(uint16_t x, uint16_t y, uint8_t power, uint8_t initiative, World* world);
    ~Organism();
    static direction getRandomDirection();
    static bool isEveryDirectionChecked(const bool* directions);

public:
    virtual void action() = 0;
    virtual void collision(Organism& organism) = 0;

    World* getWorld() const;
    uint16_t getX() const;
    uint16_t getY() const;
    uint8_t getPower() const;
    uint8_t getInitiative() const;
    virtual uint8_t getSign();

    void setPower(uint8_t power);
    void updatePosition(const uint16_t position[2]);
    uint16_t* newPosition(direction dir);
    friend std::ostream& operator<<(std::ostream& os, const Organism& organism);
};

#endif //VIRTUAL_WORLD_SIMULATION_ORGANISM_H
