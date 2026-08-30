cmake_minimum_required(VERSION 3.13)

project(DurationSorter VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Configura la ruta del SDK provista por el entorno de la Action
if(NOT DEFINED GEODE_SDK AND DEFINED ENV{GEODE_SDK})
    set(GEODE_SDK "$ENV{GEODE_SDK}")
endif()

# Carga la configuración base obligatoria de Geode
include("${GEODE_SDK}/cmake/GeodeFile.cmake")

setup_geode_mod(DurationSorter)

add_geode_mod(
    DurationSorter
    "1.0.0"
    src/main.cpp
)
