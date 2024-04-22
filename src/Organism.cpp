//
// Created by varev on 20.04.2024.
//

#include "../include/Organism.h"

#include <string>
#include <random>

#include "../include/exception/PositionException.h"

Organism::Organism(uint16_t x, uint16_t y, uint8_t power, uint8_t initiative, World* world) :
        x(x), y(y), power(power), initiative(initiative), world(world) {};

Organism::~Organism() = default;

void Organism::updatePosition(const uint16_t position[2]) {
    x = position[X];
    y = position[Y];
}

uint16_t* Organism::newPosition(direction dir) {
    uint16_t newX(x), newY(y);
    switch (dir) {
        case NORTH:
            if (newY > 0) newY--;
            break;
        case SOUTH:
            if (newY < world->getHeight() - 1) newY++;
            break;
        case WEST:
            if (newX > 0) newX--;
            break;
        case EAST:
            if (newX < world->getWidth() - 1) newX++;
            break;
    }
    return new uint16_t[2]{newX,newY};
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

void Organism::setPower(uint8_t updated) {
    this->power = updated;
}

uint8_t Organism::getInitiative() const {
    return initiative;
}

uint8_t Organism::getSign() {
    return sign;
}

std::ostream& operator<<(std::ostream& os, const Organism &organism) {
    std::string message;
    message = organism.sign;
    message.append(" (" + std::to_string(organism.x) + "; " + std::to_string(organism.y) + ")");
    os << message;
    return os;
}

bool Organism::isEveryDirectionChecked(const bool *directions) {
    for (size_t i = 0; i <= EAST; i++) {
        if (!directions[i])
            return false;
    }
    return true;
}


direction Organism::getRandomDirection() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 3);
    direction dir;
    dir = direction(dis(gen));
    return dir;
}