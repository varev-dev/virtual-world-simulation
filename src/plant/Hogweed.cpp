//
// Created by varev on 21.04.2024.
//

#include "../../include/plant/Hogweed.h"

Hogweed::Hogweed(uint16_t x, uint16_t y, World *world) :
        Plant(x, y, world) {
    sign = 'H';
}

void Hogweed::action() {
    Plant::action();
}

void Hogweed::collision(Organism &organism) {
    Plant::collision(organism);
}
