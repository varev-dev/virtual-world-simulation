//
// Created by varev on 4/23/24.
//

#ifndef VIRTUAL_WORLD_SIMULATION_GAME_H
#define VIRTUAL_WORLD_SIMULATION_GAME_H

#include "World.h"

class Game {
private:
    World* world;
    static std::filesystem::path SAVE_PATH;
public:
    Game(World *world);
    void createWorld();
    bool saveWorld();
    void loadWorld();
};

#endif //VIRTUAL_WORLD_SIMULATION_GAME_H
