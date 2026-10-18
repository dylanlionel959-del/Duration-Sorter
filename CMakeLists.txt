cmake_minimum_required(VERSION 3.13)

project(DurationSorter VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Forzar la ruta exacta que muestra el log de la Action de GitHub
if(EXISTS "/home/runner/work/Duration-Sorter/Duration-Sorter/geode-sdk-clone/Geode.cmake")
    include(/home/runner/work/Duration-Sorter/Duration-Sorter/geode-sdk-clone/Geode.cmake)
elseif(DEFINED ENV{GEODE_SDK} AND EXISTS "$ENV{GEODE_SDK}/Geode.cmake")
    include($ENV{GEODE_SDK}/Geode.cmake)
else()
    message(FATAL_ERROR "No se pudo encontrar Geode.cmake en la ruta del runner.")
endif()

add_geode_mod(
    DurationSorter
    "1.0.0"
    src/main.cpp
)
