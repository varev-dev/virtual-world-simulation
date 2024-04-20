//
// Created by varev on 04.04.2024.
//

#ifndef VIRTUAL_WORLD_SIMULATION_WORLD_H
#define VIRTUAL_WORLD_SIMULATION_WORLD_H

#include <cinttypes>
#include <vector>

#include "Organism.h"
class Organism;

class World {
private:
    uint16_t width, length;
    std::vector<Organism*> organisms;
public:
    World(uint16_t width, uint16_t length);
    uint16_t getWidth() const;
    uint16_t getHeight() const;

    void makeTurn();
    void printWorld();
    void createOrganism(Organism* organism);
    void modifyOrganism(Organism* organism);

    ~World();
};

#endif //VIRTUAL_WORLD_SIMULATION_WORLD_H
