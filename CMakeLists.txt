cmake_minimum_required(VERSION 3.13)

project(DurationSorter VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Incluye las macros de Geode desde la ruta exacta que usa el runner de GitHub Actions
include("$ENV{GEODE_SDK}/share/geode/cmake/GeodeFile.cmake")

add_geode_mod(
    DurationSorter
    "1.0.0"
    src/main.cpp
)
