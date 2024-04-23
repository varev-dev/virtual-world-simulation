//
// Created by varev on 21.04.2024.
//

#include "../../include/plant/Belladonna.h"

char Belladonna::ID = Plant::DERIVED++;

Belladonna::Belladonna(uint16_t x, uint16_t y, World *world) :
    Plant(x, y, world) {
    sign = 'b';
    name = "Wilcze Jagody";
}

void Belladonna::collision(Organism &organism) {
    world->removeOrganism(organism);
}
