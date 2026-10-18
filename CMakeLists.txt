cmake_minimum_required(VERSION 3.13)

project(DurationSorter VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Comprobación de múltiples rutas posibles para asegurar que cargue Geode.cmake sin errores
if(DEFINED ENV{GEODE_SDK} AND EXISTS "$ENV{GEODE_SDK}/Geode.cmake")
    include($ENV{GEODE_SDK}/Geode.cmake)
elseif(EXISTS "/home/runner/geode-sdk/Geode.cmake")
    include(/home/runner/geode-sdk/Geode.cmake)
elseif(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/geode-sdk/Geode.cmake")
    include(${CMAKE_CURRENT_SOURCE_DIR}/geode-sdk/Geode.cmake)
elseif(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/geode-sdk-clone/Geode.cmake")
    include(${CMAKE_CURRENT_SOURCE_DIR}/geode-sdk-clone/Geode.cmake)
else()
    message(FATAL_ERROR "No se pudo encontrar Geode.cmake en ninguna de las rutas conocidas del sistema o del repositorio.")
endif()

add_geode_mod(
    DurationSorter
    "1.0.0"
    src/main.cpp
)
