cmake_minimum_required(VERSION 3.21)

project(DurationSorter VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Forzamos la ruta del SDK instalada en el entorno actual de GitHub Actions
set(Geode_DIR "$ENV{GEODE_SDK}")

find_package(Geode REQUIRED)

add_geode_mod(
    DurationSorter
    "1.0.0"
    src/main.cpp
    src/star.cpp
)
