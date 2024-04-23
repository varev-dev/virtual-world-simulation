//#pragma once
#include <iostream>
#include <unistd.h>
#include <ncurses.h>
#include "include/Game.h"

int main() {
    //initscr();
    //raw();
    //keypad(stdscr, TRUE);

    Game game = Game();
    game.createWorld();
    game.saveWorld();

//    world->initOrganisms();
//
//    char input = '\0';
//    while (input != 'K' && input != 'k') {
//        world->printWorld();
//        input = getch();
//
//        if (input == 'P' || input == 'p')
//            world->makeTurn();
//        usleep(500000);
//    }

    //endwin();
    return 0;
}
