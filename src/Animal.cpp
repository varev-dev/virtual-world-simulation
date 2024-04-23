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
    Organism::sign = 'A';
    lastActionTurn = world->getTurn() ? JUST_BORN : FREE;
}

void Animal::action(bool canBeOccupied) {
    bool checked[4] = {false, false, false, false};
    while (!Organism::isEveryDirectionChecked(checked)) {
        direction dir = getRandomDirection();

        if (checked[dir]) continue;
        checked[dir] = true;

        uint16_t* position = newPosition(dir);

        if (position[X] == x && position[Y] == y)
            continue;

        Organism* collider = world->getOrganismByPosition(position[X], position[Y]);

        if (!canBeOccupied && collider) {
            delete[] position;
            continue;
        }

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
    if (power <= organism.getPower()) world->removeOrganism(*this);
    else world->removeOrganism(organism);
}

bool Animal::birth() {
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

        Organism* organism;

        if (dynamic_cast<Wolf*>(this))
            organism = new Wolf(position[X], position[Y], world);
        else if (dynamic_cast<Fox*>(this))
            organism = new Fox(position[X], position[Y], world);
        else if (dynamic_cast<Sheep*>(this))
            organism = new Sheep(position[X], position[Y], world);

        world->addOrganism(*organism);
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
