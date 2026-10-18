cmake_minimum_required(VERSION 3.13)

project(DurationSorter VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Incluye de forma segura el SDK de Geode provisto por el entorno de la Action
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/geode-sdk/Geode.cmake")
    include(${CMAKE_CURRENT_SOURCE_DIR}/geode-sdk/Geode.cmake)
elseif(DEFINED ENV{GEODE_SDK} AND EXISTS "$ENV{GEODE_SDK}/Geode.cmake")
    include($ENV{GEODE_SDK}/Geode.cmake)
else()
    message(FATAL_ERROR "No se encontró el SDK de Geode.")
endif()

# Registramos todos los archivos fuente de nuestro mod
add_geode_mod(
    DurationSorter
    "1.0.0"
    src/main.cpp
    src/star.cpp
)
