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
}

void Turtle::collision(Organism &organism) {
    if (auto* other = dynamic_cast<Turtle*>(&organism)) {
        birth() ?: other->birth();
        return;
    }

    if (organism.getPower() < MAX_POWER_TO_IGNORE) return;
    Animal::collision(organism);
}

void Turtle::action(bool canBeOccupied, bool dodgeStronger) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 3);

    if (dis(gen) == 0) Animal::action();
}


