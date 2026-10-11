cmake_minimum_required(VERSION 3.13)

project(DurationSorter VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Incluye directamente el script principal del SDK provisto por el entorno de Geode
if(DEFINED ENV{GEODE_SDK})
    include($ENV{GEODE_SDK}/Geode.cmake)
else()
    include(${CMAKE_CURRENT_SOURCE_DIR}/geode-sdk/Geode.cmake)
endif()

add_geode_mod(
    DurationSorter
    "1.0.0"
    src/main.cpp
)
