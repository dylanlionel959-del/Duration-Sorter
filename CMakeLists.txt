cmake_minimum_required(VERSION 3.13)

project(DurationSorter VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Incluye directamente el archivo de configuración desde la carpeta que clona el SDK
include("${CMAKE_CURRENT_SOURCE_DIR}/geode-sdk-clone/geode.cmake")

add_geode_mod(
    DurationSorter
    "1.0.0"
    src/main.cpp
)
