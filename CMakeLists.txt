cmake_minimum_required(VERSION 3.13)

project(DurationSorter VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Incluye el SDK utilizando la ruta absoluta exacta del runner de GitHub Actions
include("/home/runner/work/Duration-Sorter/Duration-Sorter/geode-sdk-clone/Geode.cmake")

add_geode_mod(
    DurationSorter
    "1.0.0"
    src/main.cpp
)
