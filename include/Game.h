//
// Created by varev on 4/23/24.
//

#ifndef VIRTUAL_WORLD_SIMULATION_GAME_H
#define VIRTUAL_WORLD_SIMULATION_GAME_H

#include "World.h"
#include <fstream>
#include <filesystem>

class Game {
private:
    World* world;
    static std::filesystem::path SAVE_PATH;
public:
    Game();
    void createWorld();
    bool saveWorld();
    void loadWorld();
    void simulate();
};

#endif //VIRTUAL_WORLD_SIMULATION_GAME_H
