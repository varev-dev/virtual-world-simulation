//
// Created by varev on 21.04.2024.
//

#include <iostream>
#include "../include/Plant.h"

Plant::Plant(uint16_t x, uint16_t y, uint8_t power, uint8_t initiative, World *world) :
        Organism(x, y, power, initiative, world) {
    Organism::sign = 'P';
};

void Plant::collision(Organism &organism) {
    world->removeOrganism(*this);
    organism.updatePosition(new uint16_t[2]{x, y});
}

void Plant::action() {

}
