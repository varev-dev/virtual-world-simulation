//
// Created by varev on 4/23/24.
//

#include <iostream>
#include <filesystem>
#include <fstream>

#include "../include/Game.h"

std::filesystem::path Game::SAVE_PATH = "saves";

Game::Game(World *world) : world(world) {}

void Game::createWorld() {
    uint16_t w = 0, h = 0;

    while (w < 1 || h < 1) {
        std::cout << "Enter width: ";
        std::cin >> w;
        std::cout << "Enter height: ";
        std::cin >> h;
    }

    world = new World(w, h);
}

