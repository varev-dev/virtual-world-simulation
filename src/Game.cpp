//
// Created by varev on 4/23/24.
//

#include <iostream>
#include <filesystem>
#include <fstream>

#include "../include/Game.h"

std::filesystem::path Game::SAVE_PATH = "saves";
char Game::EXIT_KEY = 'E';
char Game::NEXT_TURN_KEY = 'P';
char Game::USE_SKILL_KEY = 'U';

Game::Game() = default;

void Game::createWorld() {
    uint16_t w = 0, h = 0;

    while (w < 1 || h < 1) {
        std::cout << "Enter width: ";
        std::cin >> w;
        std::cout << "Enter height: ";
        std::cin >> h;
    }

    world = new World(w, h);
    world->initOrganisms();
}

bool Game::saveWorld() {
    std::string fn;
    std::cout << "Enter filename: ";
    std::cin >> fn;

    if (!std::filesystem::exists(Game::SAVE_PATH))
        std::filesystem::create_directory(Game::SAVE_PATH);

    fn.append(".save");
    std::filesystem::path filepath = Game::SAVE_PATH / fn;
    std::ofstream file(filepath);

    if (!file.is_open()) {
        std::cerr << "Failed to create file" << filepath << std::endl;
        return false;
    }

    file << world->getTurn() << " " << world->getWidth() << " " << world->getHeight() << "\n";

    for (auto* org : world->getOrganisms())
        file << *org << std::endl;

    file.close();
    return true;
}

void Game::loadWorld() {

}

void Game::simulate() {
    int input = 0;
    while (input != EXIT_KEY) {
        input = getchar();

        if (input == NEXT_TURN_KEY) world->makeTurn();
    }
}
