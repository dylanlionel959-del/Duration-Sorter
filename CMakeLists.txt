cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 20)

project(DurationSorter)

find_package(Geode REQUIRED)

add_library(${PROJECT_NAME} SHARED
    src/main.cpp
)

setup_geode_mod(${PROJECT_NAME})
