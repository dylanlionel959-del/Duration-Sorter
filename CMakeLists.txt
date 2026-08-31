cmake_minimum_required(VERSION 3.13)

project(DurationSorter VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Lee la variable de entorno que define la Action y carga las macros de Geode
set(GEODE_SDK "$ENV{GEODE_SDK}")
include("${GEODE_SDK}/geode.cmake")

add_geode_mod(
    DurationSorter
    "1.0.0"
    src/main.cpp
)
