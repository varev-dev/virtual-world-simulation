//
// Created by varev on 22.04.2024.
//

#include "../../include/animal/Sheep.h"

Sheep::Sheep(uint16_t x, uint16_t y, World *world) : Animal(x, y, world) {
    sign = 'P';
    power = 4;
    initiative = 4;
}

void Sheep::collision(Organism &organism) {
    if (auto* other = dynamic_cast<Sheep*>(&organism)) {
        birth() ? : other->birth();
        return;
    }
    Animal::collision(organism);
}
