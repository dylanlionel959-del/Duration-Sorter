cmake_minimum_required(VERSION 3.13)

project(DurationSorter VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Incluye el sistema de compilación oficial provisto por el CLI de Geode
if(DEFINED ENV{GEODE_SDK})
    include("$ENV{GEODE_SDK}/cmake/GeodeFile.cmake")
else()
    find_package(Geode REQUIRED)
endif()

add_geode_mod(
    DurationSorter
    "1.0.0"
    src/main.cpp
)
