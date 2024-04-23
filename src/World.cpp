//
// Created by varev on 20.04.2024.
//

#include "../include/World.h"

#include <iostream>
#include <random>

#include "../include/plant/Belladonna.h"
#include "../include/plant/Grass.h"
#include "../include/plant/Hogweed.h"
#include "../include/plant/Guarana.h"
#include "../include/plant/Sonchus.h"
#include "../include/Animal.h"

uint8_t World::PERCENT_OF_PLANTS = 12,
        World::PERCENT_OF_ANIMALS = 15;

World::World(uint16_t width, uint16_t height) : width(width), height(height), turn(0) {}

void World::addOrganism(Organism &organism) {
    if (dynamic_cast<Plant*>(&organism)) {
        organisms.push_back(&organism);
        return;
    }

    size_t id = organisms.size();
    for (size_t i = 0; i < organisms.size(); i++) {
        if (organism.getX() == organisms[i]->getX() && organism.getY() == organisms[i]->getY())
            continue;

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
    return nullptr;
}

uint16_t World::getWidth() const {
    return width;
}

uint16_t World::getHeight() const {
    return height;
}

int32_t World::getTurn() const {
    return turn;
}

void World::printWorld() {
    std::cout << "Turn " << turn << std::endl;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            Organism* org = getOrganismByPosition(j, i);
            std::cout << (char) (org ? org->getSign() : '-');
        }
        std::cout << std::endl;
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

void World::growPlant(Organism &organism, uint16_t *position) {
    if (dynamic_cast<Belladonna*>(&organism))
        addOrganism(*(new Belladonna(position[X], position[Y], this)));
    else if (dynamic_cast<Sonchus*>(&organism))
        addOrganism(*(new Sonchus(position[X], position[Y], this)));
    else if (dynamic_cast<Hogweed*>(&organism))
        addOrganism(*(new Hogweed(position[X], position[Y], this)));
    else if (dynamic_cast<Guarana*>(&organism))
        addOrganism(*(new Guarana(position[X], position[Y], this)));
    else if (dynamic_cast<Grass*>(&organism))
        addOrganism(*(new Grass(position[X], position[Y], this)));
}

bool World::doesOrganismExists(Organism& organism) {
    for (auto* org : organisms) {
        if (org == &organism)
            return true;
    }
    return false;
}

void World::makeTurn() {
    turn++;

    for (auto* org : organisms) {
        if (auto* animal = dynamic_cast<Animal*>(org)) {
            if (animal->getLastActionTurn() == Organism::JUST_BORN)
                animal->setLastActionTurn(Organism::FREE);
        }
    }

    size_t id = 0;
    while (true) {
        if (id >= organisms.size())
            break;
        Organism& org = *organisms[id];
        if (!doesOrganismExists(*organisms[id])) {
            id++;
            continue;
        }
        if (auto* animal = dynamic_cast<Animal*>(organisms[id])) {
            if (animal->getLastActionTurn() == Animal::JUST_BORN) {
                id++;
                continue;
            }
        }
        organisms[id]->action(true);

        if (&org == organisms[id])
            id++;
    }
}

bool World::isWorldFull() {
    return organisms.size() == (width * height);
}

bool World::isPositionLegal(uint16_t x, uint16_t y) const {
    if (x < 0 || x >= width)
        return false;
    if (y < 0 || y >= height)
        return false;

    return true;
}

void World::initOrganisms() {
    int animals = width * height * PERCENT_OF_ANIMALS / 100;
    int plants = width * height * PERCENT_OF_PLANTS / 100;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> x(0, width-1), y(0, height-1);

    uint16_t position[2];



    for (int i = 0; i < animals + plants;) {
        position[X] = x(gen);
        position[Y]= y(gen);

        if (getOrganismByPosition(position[X], position[Y])) continue;
        else i++;

        if (i < animals) addOrganism(*(Animal::createRandom(position[X], position[Y], *this)));
        else addOrganism(*(Plant::createRandom(position[X], position[Y], *this)));
    }
}
