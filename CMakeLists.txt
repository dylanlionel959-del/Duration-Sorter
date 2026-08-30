cmake_minimum_required(VERSION 3.13)

project(DurationSorter VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Configura la ruta de búsqueda oficial para que CMake encuentre la configuración de Geode
set(Geode_DIR "$ENV{GEODE_SDK}")

find_package(Geode REQUIRED)

add_geode_mod(
    DurationSorter
    "1.0.0"
    src/main.cpp
)
