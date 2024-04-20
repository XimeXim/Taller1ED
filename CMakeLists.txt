cmake_minimum_required(VERSION 3.26)
project(Taller1ED)

set(CMAKE_CXX_STANDARD 14)

include_directories(Taller1ED)

add_executable(Taller1ED
        Taller1ED/estanteria.cpp
        Taller1ED/estanteria.h
        Taller1ED/main.cpp
        Taller1ED/NodoZapato.cpp
        Taller1ED/NodoZapato.h
        Taller1ED/Zapato.cpp
        Taller1ED/Zapato.h)
