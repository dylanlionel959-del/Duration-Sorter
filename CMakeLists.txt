cmake_minimum_required(VERSION 3.21)

project(DurationSorter VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Inclusión directa utilizando la ruta absoluta del workspace donde la acción instala el SDK
include(${CMAKE_SOURCE_DIR}/geode-sdk-clone/Geode.cmake)

add_geode_mod(
    DurationSorter
    "1.0.0"
    src/main.cpp
    src/star.cpp
)
