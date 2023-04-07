cmake_minimum_required(VERSION 3.24)
project(proyecto_RF)

set(CMAKE_CXX_STANDARD 17)

add_executable(proyecto_RF main.cpp Habitat.h Habitat.cpp Animal.h Animal.cpp Sistema.h Sistema.cpp Alimento.h Alimento.cpp)
