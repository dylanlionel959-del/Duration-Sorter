cmake_minimum_required(VERSION 3.13)

project(DurationSorter VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(DEFINED ENV{GEODE_SDK})
    include("$ENV{GEODE_SDK}/share/geode/cmake/GeodeFile.cmake")
else()
    message(FATAL_ERROR "Unable to find Geode SDK! Please set GEODE_SDK environment variable.")
endif()

setup_geode_mod(${PROJECT_NAME})
