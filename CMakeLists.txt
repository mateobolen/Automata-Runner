cmake_minimum_required(VERSION 3.29)
project(Automaton)

set(CMAKE_CXX_STANDARD 20)

add_executable(Automaton main.cpp
        State.h
        DFA.h)
