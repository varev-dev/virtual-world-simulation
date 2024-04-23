//
// Created by varev on 22.04.2024.
//

#include "../../include/animal/Wolf.h"

char Wolf::ID = Animal::DERIVED++;

Wolf::Wolf(uint16_t x, uint16_t y, World *world) : Animal(x, y, world) {
    sign = 'W';
    power = 9;
    initiative = 5;
}

void Wolf::collision(Organism &organism) {
    if (auto* other = dynamic_cast<Wolf*>(&organism)) {
        birth() ? : other->birth();
        return;
    }
    Animal::collision(organism);
}
