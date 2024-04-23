//
// Created by varev on 4/23/24.
//

#include <iostream>
#include <filesystem>
#include <fstream>

#include "../include/Game.h"
#include "../include/Human.h"
#include "../include/animal/Antelope.h"
#include "../include/animal/Fox.h"
#include "../include/animal/Sheep.h"
#include "../include/animal/Wolf.h"
#include "../include/animal/Turtle.h"
#include "../include/plant/Belladonna.h"
#include "../include/plant/Grass.h"
#include "../include/plant/Guarana.h"
#include "../include/plant/Hogweed.h"
#include "../include/plant/Sonchus.h"

std::filesystem::path Game::SAVE_PATH = "saves";
char Game::EXIT_KEY = 'E';
char Game::NEXT_TURN_KEY = 'P';
char Game::USE_SKILL_KEY = 'U';
char Game::SAVE_KEY = 'S';

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

void Game::initBySign(char sign, uint16_t x, uint16_t y, uint8_t power, uint16_t action) {
    Organism* organism;

    switch (sign) {
        case 'H': organism = new Human(x, y, power, action, world); world->setHuman(organism); break;
        case 'A': organism = new Antelope(x, y, power, action, world); break;
        case 'F': organism = new Fox(x, y, power, action, world); break;
        case 'P': organism = new Sheep(x, y, power, action, world); break;
        case 'W': organism = new Wolf(x, y, power, action, world); break;
        case 'T': organism = new Turtle(x, y, power, action, world); break;
        case 'b': organism = new Belladonna(x, y, world); break;
        case 't': organism = new Grass(x, y, world); break;
        case 'g': organism = new Guarana(x, y, world); break;
        case 'h': organism = new Hogweed(x, y, world); break;
        case 's': organism = new Sonchus(x, y, world); break;
        default: return;
    }

    world->addOrganism(*organism);
}

bool Game::loadWorld() {
    std::string fn;
    std::cout << "Enter filename: ";
    std::cin >> fn;

    if (!std::filesystem::exists(Game::SAVE_PATH)) {
        std::filesystem::create_directory(Game::SAVE_PATH);
        return false;
    }

    fn.append(".save");
    std::filesystem::path fp = Game::SAVE_PATH / fn;
    std::ifstream file(fp);

    if (!file.is_open())
        return false;

    delete world;

    int turn, width, height;
    file >> turn >> width >> height;

    std::string line;
    this->world = new World((uint16_t) width, (uint16_t) height);
    this->world->setTurn(turn);
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::vector<uint16_t> param;
        int num;
        while (iss >> num) param.push_back(num);

        if (param.size() == 5)
            initBySign((char) param[0], param[1], param[2], (uint8_t) param[3], param[4]);
    }

    file.close();
    return true;
}

bool isMoveKey(int input) {
    return input == 'W' || input == 'S' || input == 'A' || input == 'D';
}

void Game::simulate() {
    int input = 0;
    while (input != EXIT_KEY) {
        world->printWorld();
        input = getchar();

        if (input == SAVE_KEY) saveWorld();
        else if (input == NEXT_TURN_KEY) world->makeTurn();
        else if (isMoveKey(input) || input == Game::USE_SKILL_KEY) {
            if (!world->getHuman()) continue;

            auto* human = dynamic_cast<Human*>(world->getHuman());
            human->setOption(input);
            world->makeTurn();
        }
    }
}
