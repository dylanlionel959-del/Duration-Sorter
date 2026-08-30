cmake_minimum_required(VERSION 3.13)

project(DurationSorter VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Si la variable no viene definida por CLI, toma la del entorno del runner
if(NOT GEODE_SDK)
    set(GEODE_SDK "$ENV{GEODE_SDK}")
endif()

# Carga la configuración nativa del SDK de Geode
include("${GEODE_SDK}/share/geode/cmake/GeodeFile.cmake")

# Inicializa el mod
setup_geode_mod(DurationSorter)

add_geode_mod(
    DurationSorter
    "1.0.0"
    src/main.cpp
)
