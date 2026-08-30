cmake_minimum_required(VERSION 3.13)

project(DurationSorter VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Incluye directamente el archivo de configuración del SDK provisto por el entorno
include($ENV{GEODE_SDK}/geode.cmake OPTIONAL)

if(NOT TARGET geode)
    # Fallback por si la ruta requiere el subdirectorio de CMake estándar
    include($ENV{GEODE_SDK}/cmake/GeodeFile.cmake OPTIONAL)
endif()

add_geode_mod(
    DurationSorter
    "1.0.0"
    src/main.cpp
)
