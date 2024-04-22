//
// Created by varev on 21.04.2024.
//

#include "../../include/plant/Belladonna.h"

Belladonna::Belladonna(uint16_t x, uint16_t y, World *world) :
    Plant(x, y, world) {
    sign = 'B';
}

void Belladonna::collision(Organism &organism) {
    world->removeOrganism(organism);
}
