//
// Created by varev on 04.04.2024.
//

#include "../include/Animal.h"
#include "../include/plant/Guarana.h"

#include <random>
#include <iostream>

direction randomizeDirection(const Organism& organism) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 3);
    bool isMoveValid = false;
    direction dir;
    while (!isMoveValid) {
        dir = direction(dis(gen));
        switch (dir) {
            case NORTH:
                if (organism.getY() != 0)
                    isMoveValid = true;
                break;
            case SOUTH:
                if (organism.getY() != organism.getWorld()->getHeight() - 1)
                    isMoveValid = true;
                break;
            case WEST:
                if (organism.getX() != 0)
                    isMoveValid = true;
                break;
            case EAST:
                if (organism.getX() != organism.getWorld()->getWidth() - 1)
                    isMoveValid = true;
                break;
            default:
                std::cout << "Unknown direction";
                break;
        }
    }
    return dir;
}

void Animal::action() {
    direction dir = randomizeDirection(*this);
    uint16_t* position = newPosition(dir);

    Organism* collider;

    for (auto org : world->getOrganisms()) {
        if (org->getX() != position[X])
            continue;
        if (org->getY() != position[Y])
            continue;

        collider = org;
    }

    collider->collision(*this);
}