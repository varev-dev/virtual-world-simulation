//
// Created by varev on 04.04.2024.
//

#include "../includes/Animal.h"

#include <random>
#include <iostream>

#define NORTH 0
#define SOUTH 1
#define WEST 2
#define EAST 3

void Animal::action(World &world) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 3);
    bool isMoveValid = false;
    while (!isMoveValid) {
        int direction = dis(gen);

        switch (direction) {
            case NORTH:
                if (y != 0)
                    isMoveValid = true;
                break;
            case SOUTH:
                if (y != world.getHeight() - 1)
                    isMoveValid = true;
                break;
            case WEST:
                if (x != 0)
                    isMoveValid = true;
                break;
            case EAST:
                if (x != world.getWidth() - 1)
                    isMoveValid = true;
                break;
            default:
                std::cout << "unknown direction";
                break;
        }
    }
}

void Animal::collision(World &world) {

}