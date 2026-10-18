cmake_minimum_required(VERSION 3.21)

project(DurationSorter VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Incluimos de forma segura usando la ruta relativa del clon del SDK que hace la acción
include(${CMAKE_CURRENT_SOURCE_DIR}/geode-sdk-clone/Geode.cmake)

add_geode_mod(
    DurationSorter
    "1.0.0"
    src/main.cpp
    src/star.cpp
)
