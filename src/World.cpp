//
// Created by varev on 20.04.2024.
//

#include <iostream>
#include "../include/World.h"

#include "../include/exception/PositionException.h"

World::World(uint16_t width, uint16_t height) : width(width), height(height), turn(0) {}

void World::addOrganism(Organism &organism) {
    size_t id = organisms.size();
    for (size_t i = 0; i < organisms.size(); i++) {
        if (organism.getX() == organisms[i]->getX() && organism.getY() == organisms[i]->getY())
            throw PositionException("Position already in use.");

        if (organisms[i]->getInitiative() >= organism.getInitiative())
            continue;

        if (id == organisms.size())
            id = i;
    }
    organisms.insert(organisms.begin() + id, &organism);
}

std::vector<Organism*> World::getOrganisms() {
    return organisms;
}

Organism* World::getOrganismByPosition(uint16_t x, uint16_t y) {
    for (auto &organism : organisms) {
        if (x != organism->getX())
            continue;
        if (y != organism->getY())
            continue;

        return organism;
    }
    throw PositionException("No organism with given position");
}

uint16_t World::getWidth() const {
    return width;
}

uint16_t World::getHeight() const {
    return height;
}

uint32_t World::getTurn() const {
    return turn;
}

void World::printWorld() {
    std::cout << "Turn " << turn << std::endl;
    for (const auto &item: organisms) {
        std::cout << *item << ", ";
    }
    std::cout << std::endl;
}

void World::removeOrganism(Organism &organism) {
    for (int id = 0; id < organisms.size(); id++) {
        if (&organism == organisms[id]) {
            organisms.erase(organisms.begin() + id);
            break;
        }
    }
}
