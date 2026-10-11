cmake_minimum_required(VERSION 3.13)

project(DurationSorter VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Si la variable de entorno GEODE_SDK existe, la usamos; si no, buscamos en la ruta estándar del runner
if(DEFINED ENV{GEODE_SDK} AND NOT "$ENV{GEODE_SDK}" STREQUAL "")
    include($ENV{GEODE_SDK}/Geode.cmake)
else()
    include(/home/runner/geode-sdk/Geode.cmake)
endif()

add_geode_mod(
    DurationSorter
    "1.0.0"
    src/main.cpp
)
