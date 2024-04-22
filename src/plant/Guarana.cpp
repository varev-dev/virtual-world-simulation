//
// Created by varev on 20.04.2024.
//

#include "../../include/plant/Guarana.h"

uint8_t Guarana::STRENGTH_INCREASE = 3;

Guarana::Guarana(uint16_t x, uint16_t y, World *world) :
        Plant(x, y, world) {
    sign = 'G';
};

void Guarana::collision(Organism &organism) {
    organism.setPower(organism.getPower() + STRENGTH_INCREASE);
    Plant::collision(organism);
}