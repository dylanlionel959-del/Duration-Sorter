cmake_minimum_required(VERSION 3.13)

project(DurationSorter VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Si GEODE_SDK no está en el entorno global, buscarlo en la ruta por defecto del CLI de Linux/Android
if(NOT DEFINED ENV{GEODE_SDK})
    set(ENV{GEODE_SDK} "$ENV{HOME}/.local/share/geode/sdk")
endif()

list(APPEND CMAKE_PREFIX_PATH "$ENV{GEODE_SDK}")
include("$ENV{GEODE_SDK}/share/geode/cmake/GeodeFile.cmake")

add_geode_mod(
    DurationSorter
    "1.0.0"
    src/main.cpp
)

