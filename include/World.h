//
// Created by varev on 04.04.2024.
//

#ifndef VIRTUAL_WORLD_SIMULATION_WORLD_H
#define VIRTUAL_WORLD_SIMULATION_WORLD_H

#include <cinttypes>
#include <vector>
#include <memory>

#include "Organism.h"
class Organism;

class World {
private:
    uint16_t width, height;
    uint32_t turn;
    std::vector<Organism*> organisms;
public:
    World(uint16_t width, uint16_t height);
    ~World();

    uint16_t getWidth() const;
    uint16_t getHeight() const;
    uint32_t getTurn() const;

    void addOrganism(Organism& organism);
    std::vector<Organism*> getOrganisms();
    void removeOrganism(Organism& organism);
    Organism* getOrganismByPosition(uint16_t x, uint16_t y);

    void makeTurn();
    void printWorld();
};

#endif //VIRTUAL_WORLD_SIMULATION_WORLD_H
