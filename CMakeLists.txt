cmake_minimum_required(VERSION 3.17.2)

project(Algorithms-Playground
  VERSION 0.8.7
  LANGUAGES CXX)


set(BUILD_SHARED_LIBS YES)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS NO)

###---This slows down compilation dramatically---###
# set(CMAKE_CXX_CLANG_TIDY clang-tidy)

add_subdirectory(src)
