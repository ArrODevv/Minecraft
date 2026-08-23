cmake_minimum_required(VERSION 4.3)

project(Minecraft VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(SRC
    src/main.cxx
)

add_executable(minecraft ${SRC})
target_include_directories(minecraft PRIVATE src/)
