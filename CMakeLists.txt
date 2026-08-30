cmake_minimum_required(VERSION 3.13)

project(DurationSorter VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Añade la ruta del SDK provista por la Action al prefijo de búsqueda de CMake
list(APPEND CMAKE_PREFIX_PATH "$ENV{GEODE_SDK}")

find_package(Geode REQUIRED)

add_geode_mod(
    DurationSorter
    "1.0.0"
    src/main.cpp
)
