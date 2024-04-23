//
// Created by varev on 23.04.2024.
//

#include <random>
#include "../../include/animal/Antelope.h"

char Antelope::ID = Animal::DERIVED++;

Antelope::Antelope(uint16_t x, uint16_t y, World *world) : Animal(x, y, world) {
    power = 4;
    initiative = 4;
}

void Antelope::action(bool canBeOccupied) {
    Animal::action();
    Animal::action();
}

void Antelope::collision(Organism &organism) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);

    if (dis(gen) == 0) {
        bool checked[4] = {false, false, false, false};
        while (!Organism::isEveryDirectionChecked(checked)) {
            direction dir = getRandomDirection();

            if (checked[dir]) continue;
            checked[dir] = true;

            uint16_t* position = newPosition(dir);

            if (position[X] == x && position[Y] == y) continue;
            if (world->getOrganismByPosition(position[X], position[Y])) continue;

            updatePosition(position);

            delete[] position;
            break;
        }
    } else Animal::collision(organism);
}

