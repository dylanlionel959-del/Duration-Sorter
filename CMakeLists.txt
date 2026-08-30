cmake_minimum_required(VERSION 3.13)

project(DurationSorter VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# Descarga automáticamente las macros de CMake oficial de Geode si el SDK local no está presente
if(NOT DEFINED ENV{GEODE_SDK})
    message(STATUS "GEODE_SDK no detectado, configurando vía Geode CLI...")
endif()

find_package(Geode REQUIRED)

add_geode_mod(
    DurationSorter
    "1.0.0"
    src/main.cpp
)
