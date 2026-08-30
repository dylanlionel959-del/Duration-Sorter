cmake_minimum_required(VERSION 3.13)

project(DurationSorter VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Configura explícitamente el directorio del SDK para que find_package lo localice sin fallar
set(Geode_SDK "$ENV{GEODE_SDK}")
list(APPEND CMAKE_PREFIX_PATH "${Geode_SDK}")

find_package(Geode REQUIRED)

add_geode_mod(
    DurationSorter
    "1.0.0"
    src/main.cpp
)
