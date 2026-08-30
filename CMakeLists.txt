cmake_minimum_required(VERSION 3.13)

project(DurationSorter VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ruta local del SDK dentro del repositorio o la proporcionada por el entorno
if(NOT DEFINED GEODE_SDK)
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/geode-sdk")
        set(GEODE_SDK "${CMAKE_CURRENT_SOURCE_DIR}/geode-sdk")
    elseif(DEFINED ENV{GEODE_SDK})
        set(GEODE_SDK "$ENV{GEODE_SDK}")
    endif()
endif()

# Incluye las macros oficiales del SDK para que reconozca setup_geode_mod y add_geode_mod
include("${GEODE_SDK}/cmake/GeodeFile.cmake")

setup_geode_mod(DurationSorter)

add_geode_mod(
    DurationSorter
    "1.0.0"
    src/main.cpp
)
