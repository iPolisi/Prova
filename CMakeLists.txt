cmake_minimum_required(VERSION 3.30)
project(Prova)

set(CMAKE_CXX_STANDARD 20)

add_executable(Prova main.cpp
        Transazione.h
        Transazione.cpp
        Entrata.h
        Entrata.cpp
        Uscita.h
        Uscita.cpp
        ContoCorrente.h
        ContoCorrente.cpp)
