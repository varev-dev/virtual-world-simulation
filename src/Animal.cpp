//
// Created by varev on 04.04.2024.
//

#include "../include/Animal.h"

#include <random>
#include <iostream>

#include "../include/animal/Fox.h"
#include "../include/animal/Sheep.h"
#include "../include/animal/Wolf.h"
#include "../include/animal/Antelope.h"
#include "../include/animal/Turtle.h"

char Animal::DERIVED = 0;

Animal::Animal(uint16_t x, uint16_t y, World *world) :
        Organism(x, y, 1, 1, world) {
    Organism::sign = 'L';
    lastActionTurn = world->getTurn() ? JUST_BORN : FREE;
}

Animal::Animal(uint16_t x, uint16_t y, uint8_t power, uint16_t action, World *world)
        : Organism(x, y, power, 1, world) {
    Organism::sign = 'L';
    lastActionTurn = action;
}

void Animal::action(bool canBeOccupied, bool dodgeStronger) {
    bool checked[4] = {false, false, false, false};
    while (!Organism::isEveryDirectionChecked(checked)) {
        direction dir = getRandomDirection();

        if (checked[dir]) continue;
        checked[dir] = true;

        uint16_t* position = newPosition(dir);

        if (position[X] == x && position[Y] == y)
            continue;

        Organism* collider = world->getOrganismByPosition(position[X], position[Y]);

        if (!canBeOccupied && collider)
            continue;

        if (dodgeStronger && collider->getPower() > power)
            continue;

        if (canBeOccupied && collider) {
            collider->collision(*this);
            lastActionTurn = (int32_t) world->getTurn();
        }

        if (!world->getOrganismByPosition(position[X], position[Y]))
            updatePosition(position);

        delete[] position;
        break;
    }
}

void Animal::collision(Organism &organism) {
    world->addMessage("Kolizja " + this->name + " " + organism.getName());
    if (power <= organism.getPower()) {world->addMessage(name + " umiera"); world->removeOrganism(*this); }
    else {world->addMessage(organism.getName() + " umiera"); world->removeOrganism(organism); }
}

bool Animal::birth(uint16_t x, uint16_t y) {
    bool checked[4] = {false,false,false,false};

    while (!Organism::isEveryDirectionChecked(checked)) {
        direction dir = getRandomDirection();

        if (checked[dir]) continue;
        checked[dir] = true;
        uint16_t* position = newPosition(dir);

        if (position[X] == x && position[Y] == y) {
            delete[] position;
            continue;
        }

        if (world->getOrganismByPosition(position[X], position[Y])) {
            delete[] position;
            continue;
        }

        this->birth(position[X], position[Y]);
        world->addMessage("Urodzone zwierze " + getName());
        lastActionTurn = (int32_t) world->getTurn();
        delete[] position;
        return true;
    }
    return false;
}

Organism *Animal::createRandom(uint16_t x, uint16_t y, World& world) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, DERIVED - 1);

    int random = dis(gen);

    if (random == Wolf::ID)
        return new Wolf(x, y, &world);
    else if (random == Fox::ID)
        return new Fox(x, y, &world);
    else if (random == Turtle::ID)
        return new Turtle(x, y, &world);
    else if (random == Antelope::ID)
        return new Antelope(x, y, &world);
    else if (random == Sheep::ID)
        return new Sheep(x, y, &world);
}