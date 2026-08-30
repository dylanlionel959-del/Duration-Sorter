cmake_minimum_required(VERSION 3.13)

project(DurationSorter VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include($ENV{GEODE_SDK}/share/geode/cmake/GeodeFile.cmake)

setup_geode_mod(
    ID "com.dylan.durationsorter"
    VERSION "1.0.0"
)

add_geode_mod(
    DurationSorter
    src/main.cpp
)
