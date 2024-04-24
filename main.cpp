//#pragma once
#include <iostream>
#include <unistd.h>
//#include <ncurses.h>
#include "include/Game.h"

int main() {
    //initscr();
    //raw();
    //keypad(stdscr, TRUE);

    Game game = Game();
    char input = 0;
    while (input != 'L' && input != 'N') {
        std::cout << "Enter letter (L - Load, N - New): ";
        std::cin >> input;
    }
    if (input == 'L')
        game.loadWorld();
    else
        game.createWorld();
    game.simulate();

    delete &game;
    //endwin();
    return 0;
}
