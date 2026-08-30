cmake_minimum_required(VERSION 3.13)

project(DurationSorter VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Carga el archivo del SDK inyectado por el entorno de la Action
include("$ENV{GEODE_SDK}/cmake/GeodeFile.cmake")

# add_geode_mod crea el target y configura todo automáticamente
add_geode_mod(
    DurationSorter
    "1.0.0"
    src/main.cpp
)
