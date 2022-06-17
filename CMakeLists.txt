cmake_minimum_required(VERSION 3.22)
project(commis_voyageur)

set(CMAKE_CXX_STANDARD 11)

add_executable(commis_voyageur main.cpp Route.cpp Route.h WeightListGraph.cpp WeightListGraph.h BoxMuller.h Experiment.cpp Experiment.h)
