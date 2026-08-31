cmake_minimum_required(VERSION 3.13)

project(DurationSorter VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Incluye Geode utilizando la ruta absoluta que provee la variable de entorno del runner
include($ENV{GEODE_SDK}/Geode.cmake)

add_geode_mod(
    DurationSorter
    "1.0.0"
    src/main.cpp
)
