cmake_minimum_required(VERSION 3.21)
project(umf4)

set(CMAKE_CXX_STANDARD 14)

add_executable(umf4 main.cpp struct.h lin_alg.h utils.h BSG.h)
