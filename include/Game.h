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
    void initBySign(char sign, uint16_t x, uint16_t y, uint8_t power, uint16_t action);
public:
    static char EXIT_KEY, NEXT_TURN_KEY, USE_SKILL_KEY, SAVE_KEY;

    Game();
    ~Game();
    void createWorld();
    bool saveWorld();
    bool loadWorld();
    void simulate();
};

#endif //VIRTUAL_WORLD_SIMULATION_GAME_H
