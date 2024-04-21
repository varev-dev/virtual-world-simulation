//
// Created by varev on 20.04.2024.
//

#ifndef VIRTUAL_WORLD_SIMULATION_POSITIONEXCEPTION_H
#define VIRTUAL_WORLD_SIMULATION_POSITIONEXCEPTION_H

#include <exception>
#include <string>
#include <utility>

class PositionException : public std::exception {
private:
    std::string message;
public:
    explicit PositionException(std::string msg) : message(std::move(msg)) {}
    std::string what() {return message;}
};

#endif //VIRTUAL_WORLD_SIMULATION_POSITIONEXCEPTION_H
