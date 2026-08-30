cmake_minimum_required(VERSION 3.13)

project(DurationSorter VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Apunta directamente a la ruta donde el action clona el SDK en el runner
set(Geode_DIR "${CMAKE_CURRENT_SOURCE_DIR}/geode-sdk-clone")
list(APPEND CMAKE_PREFIX_PATH "${Geode_DIR}")

find_package(Geode REQUIRED)

add_geode_mod(
    DurationSorter
    "1.0.0"
    src/main.cpp
)
