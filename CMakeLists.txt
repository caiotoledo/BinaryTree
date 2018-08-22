# stop if cmake version below 3.5
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

set(PROJ_NAME BinaryTree)

project(${PROJ_NAME})

file(GLOB_RECURSE SOURCES_CPP "src/*.cpp")

add_executable(${PROJ_NAME} ${SOURCES_CPP})


