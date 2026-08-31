cmake_minimum_required(VERSION 4.2)

project(Minecraft VERSION 0.0.1 LANGUAGES CXX)

set(BUILD_TYPE "RELEASE" CACHE STRING "The build configuration to use: RELEASE, DEBUG or REL_WITH_DEBUG_INFO")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

if(BUILD_TYPE STREQUAL "RELEASE")
    message(STATUS "Building in RELEASE mode")
    set(CMAKE_BUILD_TYPE "Release")
elseif(BUILD_TYPE STREQUAL "DEBUG")
    message(STATUS "Building in DEBUG mode")
    set(CMAKE_BUILD_TYPE "Debug")
elseif(BUILD_TYPE STREQUAL "REL_WITH_DEBUG_INFO")
    message(STATUS "Building in REL_WITH_DEBUG_INFO mode")
    set(CMAKE_BUILD_TYPE "RelWithDebInfo")
else()
    message(STATUS "Unsupported BUILD_TYPE : ${BUILD_TYPE}")
endif()

set(SRC
    src/main.cxx
    src/common.hpp
    src/core/logger.hpp
    src/core/logger.cpp
    src/core/fs.hpp
    src/core/fs.cpp
    src/core/util.hpp
    src/core/util.cpp
    src/math/mmath.hpp
    src/math/mmath.cpp
    src/math/vector2.hpp
    src/math/vector2.cpp
)

add_executable(minecraft ${SRC})
target_include_directories(minecraft PRIVATE src/)

if(BUILD_TYPE STREQUAL "RELEASE")
    target_compile_definitions(minecraft PRIVATE _RELEASE)
    # TODO: compiler & linker flags
elseif(BUILD_TYPE STREQUAL "DEBUG")
    target_compile_definitions(minecraft PRIVATE _DEBUG)
    # TODO: compiler & linker flags
#elseif(BUILD_TYPE STREQUAL "REL_WITH_DEBUG_INFO")
    # TODO
    #target_compile_definitions(minecraft PRIVATE _DEBUG)
    # TODO: compiler & linker flags
endif()
