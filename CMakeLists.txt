cmake_minimum_required(VERSION 3.13)

project(DurationSorter VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Asigna la variable de entorno a una variable de CMake y carga el SDK
set(GEODE_SDK_PATH "$ENV{GEODE_SDK}")
include("${GEODE_SDK_PATH}/Geode.cmake")

add_geode_mod(
    DurationSorter
    "1.0.0"
    src/main.cpp
)
