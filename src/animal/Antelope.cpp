//
// Created by varev on 23.04.2024.
//

#include <random>
#include "../../include/animal/Antelope.h"

char Antelope::ID = Animal::DERIVED++;

Antelope::Antelope(uint16_t x, uint16_t y, World *world) : Animal(x, y, world) {
    sign = 'A';
    power = 4;
    initiative = 4;
}

Antelope::Antelope(uint16_t x, uint16_t y, uint8_t power, uint8_t initiative, World *world)
        : Animal(x, y, power, initiative, world) {
    sign = 'A';
    this->power = power;
    this->initiative = 4;
    lastActionTurn = initiative;
}

void Antelope::action(bool canBeOccupied, bool dodgeStronger) {
    Animal::action();
    Animal::action();
}

void Antelope::collision(Organism &organism) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);

    uint16_t oldX = x, oldY = y;
    int random = dis(gen);

    if (random == 0) Animal::action(false);
    if (random || (oldX == x && oldY == y)) Animal::collision(organism);
}