//
// Created by varev on 23.04.2024.
//

#include <random>
#include "../../include/animal/Turtle.h"

char Turtle::ID = Animal::DERIVED++;
uint8_t Turtle::MAX_POWER_TO_IGNORE = 5;

Turtle::Turtle(uint16_t x, uint16_t y, World *world) : Animal(x, y, world) {
    sign = 'T';
    power = 2;
    initiative = 1;
    name = "Zolw";
}

Turtle::Turtle(uint16_t x, uint16_t y, uint8_t power, uint16_t initiative, World *world)
        : Animal(x, y, power, initiative, world) {
    sign = 'T';
    this->initiative = 1;
    name = "Zolw";
}

void Turtle::collision(Organism &organism) {
    if (dynamic_cast<Turtle*>(&organism)) {
        Animal::birth();
        return;
    }
    if (organism.getPower() < MAX_POWER_TO_IGNORE) {
        world->addMessage(name + " odbija cios");
        return;
    }
    Animal::collision(organism);
}

void Turtle::action(bool canBeOccupied, bool dodgeStronger) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 3);

    if (dis(gen) == 0) Animal::action();
}

bool Turtle::birth(uint16_t x, uint16_t y) {
    world->addOrganism(*(new Turtle(x, y, world)));
    return true;
}


