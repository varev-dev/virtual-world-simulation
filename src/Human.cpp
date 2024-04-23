//
// Created by varev on 23.04.2024.
//

#include "../include/Human.h"
#include "../include/Game.h"

uint8_t Human::SKILL_DELAY = 5;
uint8_t Human::SKILL_DURATION = 5;

Human::Human(uint16_t x, uint16_t y, World *world) : Animal(x, y, world) {
    sign = 'H';
    power = 5;
    initiative = 4;
    name = "Czlowiek";
}

Human::Human(uint16_t x, uint16_t y, uint8_t power, uint16_t skill, World *world) : Animal(x, y, power, skill, world) {
    sign = 'H';
    initiative = 4;
    name = "Czlowiek";
}

void Human::action(bool canBeOccupied, bool dodgeStronger) {
    if (!canBeOccupied)
        Animal::action(canBeOccupied);

    direction dir;
    if (option == 'W') dir = NORTH;
    else if (option == 'S') dir = SOUTH;
    else if (option == 'A') dir = WEST;
    else if (option == 'D') dir = EAST;
    else return;

    option = 0;
    uint16_t* position = newPosition(dir);

    Organism* collider = world->getOrganismByPosition(position[X], position[Y]);

    if (collider) collider->collision(*this);
    else updatePosition(position);
}

void Human::collision(Organism &organism) {
    if (lastActionTurn + SKILL_DURATION >= world->getTurn()) Animal::action(false);
    else Animal::collision(organism);
}

void Human::setOption(int opt) {
    this->option = opt;

    if (option == Game::USE_SKILL_KEY) {
        if (lastActionTurn + SKILL_DURATION + SKILL_DELAY < world->getTurn() || lastActionTurn == FREE)
            lastActionTurn = world->getTurn();
    }
}

