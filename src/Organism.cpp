//
// Created by varev on 20.04.2024.
//

#include "../includes/Organism.h"

Organism::Organism(uint16_t x, uint16_t y, uint8_t power, uint8_t initiative, World* world) :
        x(x), y(y), power(power), initiative(initiative), world(world) {};

Organism::~Organism() = default;

void Organism::updatePosition(direction dir) {
    switch (dir) {
        case NORTH:
            if (y > 0)
                this->y--;
            break;
        case SOUTH:
            if (y < world->getHeight() - 1)
                this->y++;
            break;
        case WEST:
            if (x > 0)
                this->x--;
            break;
        case EAST:
            if (x < world->getWidth() - 1)
                this->x++;
            break;
    }
}

World* Organism::getWorld() const {
    return world;
}

uint16_t Organism::getX() const {
    return x;
}

uint16_t Organism::getY() const {
    return y;
}

uint8_t Organism::getPower() const {
    return power;
}

uint8_t Organism::getInitiative() const {
    return initiative;
}

uint8_t Organism::getSign() const {
    return 'U';
}