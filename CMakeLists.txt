cmake_minimum_required(VERSION 3.26)
project(virtual_world_simulation)

set(CMAKE_CXX_STANDARD 17)

add_executable(virtual_world_simulation main.cpp
        include/World.h
        include/Animal.h
        include/Human.h
        src/Animal.cpp
        include/Organism.h
        include/Plant.h
        src/Organism.cpp
        include/exception/PositionException.h
        include/Direction.h
        tests/OrganismTest.cpp
        src/World.cpp
        include/plant/Grass.h
        include/plant/Sonchus.h
        include/plant/Guarana.h
        src/plant/Guarana.cpp
        include/plant/Belladonna.h
        include/plant/Hogweed.h
        src/Plant.cpp
        src/plant/Belladonna.cpp
        src/plant/Hogweed.cpp
        src/plant/Sonchus.cpp
        src/plant/Grass.cpp)
