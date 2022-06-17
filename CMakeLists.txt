cmake_minimum_required(VERSION 3.22)
project(commis_voyageur)

set(CMAKE_CXX_STANDARD 11)

add_executable(commis_voyageur main.cpp BoxMuller.h)

add_subdirectory(tests)

add_library(Experiment Experiment.cpp Experiment.h)
target_include_directories(Experiment PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(Route Route.cpp Route.h)
target_include_directories(Route PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(WeightListGraph WeightListGraph.cpp WeightListGraph.h)
target_include_directories(WeightListGraph PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(commis_voyageur LINK_PUBLIC Experiment Route WeightListGraph)

