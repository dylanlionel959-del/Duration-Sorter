cmake_minimum_required(VERSION 3.13)

project(DurationSorter VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Incluye las macros del SDK utilizando la variable de entorno que configura la Action
include($ENV{GEODE_SDK}/cmake/GeodeFile.cmake)

add_geode_mod(
    DurationSorter
    "1.0.0"
    src/main.cpp
)
