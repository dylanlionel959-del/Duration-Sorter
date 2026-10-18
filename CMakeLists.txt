cmake_minimum_required(VERSION 3.21)

project(DurationSorter VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Buscamos el archivo Geode.cmake en todas las rutas posibles del entorno y del runner
if(EXISTS "$ENV{GEODE_SDK}/Geode.cmake")
    include("$ENV{GEODE_SDK}/Geode.cmake")
elseif(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/geode-sdk-clone/Geode.cmake")
    include("${CMAKE_CURRENT_SOURCE_DIR}/geode-sdk-clone/Geode.cmake")
elseif(EXISTS "/home/runner/work/Duration-Sorter/Duration-Sorter/geode-sdk-clone/Geode.cmake")
    include("/home/runner/work/Duration-Sorter/Duration-Sorter/geode-sdk-clone/Geode.cmake")
else()
    message(FATAL_ERROR "No se pudo encontrar Geode.cmake en ninguna ruta conocida del sistema.")
endif()

add_geode_mod(
    DurationSorter
    "1.0.0"
    src/main.cpp
    src/star.cpp
)
