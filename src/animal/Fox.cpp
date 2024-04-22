//
// Created by varev on 22.04.2024.
//

#include "../../include/animal/Fox.h"

Fox::Fox(uint16_t x, uint16_t y, World *world) : Animal(x, y, world) {
    sign = 'F';
    power = 3;
    initiative = 7;
}

void Fox::collision(Organism &organism) {
    if (auto* other = dynamic_cast<Fox*>(&organism)) {
        birth() ? : other->birth();
        return;
    }
    Animal::collision(organism);
}

void Fox::action() {
    bool checked[4] = {false, false, false, false};
    while (!Organism::isEveryDirectionChecked(checked)) {
        direction dir = getRandomDirection();

        if (checked[dir]) continue;
        checked[dir] = true;

        uint16_t* position = newPosition(dir);

        if (position[X] == x && position[Y] == y)
            continue;

        Organism* collider = world->getOrganismByPosition(position[X], position[Y]);

        if (collider) {
            if (collider->getPower() > power) continue;
            collider->collision(*this);
            lastActionTurn = (int32_t) world->getTurn();
        }

        if (!world->getOrganismByPosition(position[X], position[Y]))
            updatePosition(position);

        delete[] position;
        break;
    }
}
