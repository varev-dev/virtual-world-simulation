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
    char* message;
public:
    explicit PositionException(char* msg) : message(msg) {}
    char* what() const noexcept override {return message;}
};

#endif //VIRTUAL_WORLD_SIMULATION_POSITIONEXCEPTION_H
