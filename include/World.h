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
    int32_t turn;
    std::vector<Organism*> organisms;
    bool doesOrganismExists(Organism& organism);
    static uint8_t PERCENT_OF_PLANTS, PERCENT_OF_ANIMALS;
public:
    World(uint16_t width, uint16_t height);
    void initOrganisms();
    uint16_t getWidth() const;
    uint16_t getHeight() const;
    int32_t getTurn() const;

    void growPlant(Organism& organism, uint16_t* position);
    void addOrganism(Organism& organism);
    std::vector<Organism*> getOrganisms();
    void removeOrganism(Organism& organism);
    Organism* getOrganismByPosition(uint16_t x, uint16_t y);
    bool isWorldFull();
    bool isPositionLegal(uint16_t x, uint16_t y) const;
    void makeTurn();
    void printWorld();
};

#endif //VIRTUAL_WORLD_SIMULATION_WORLD_H
