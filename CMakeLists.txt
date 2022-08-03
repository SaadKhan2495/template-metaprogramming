cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
project(metaprogramming)

set(default_build_type "Release")
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
      STRING "Choose the type of build." FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
    "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

message("Build type: ${CMAKE_BUILD_TYPE}")

if(${CMAKE_BUILD_TYPE} STREQUAL "Release")
    add_definitions(-DFLAGS="RELEASE: ${CMAKE_CXX_FLAGS_RELEASE}")
    message("-- Building with Flags: ${CMAKE_CXX_FLAGS_RELEASE}")
elseif(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    add_definitions(-DFLAGS="DEBUG: ${CMAKE_CXX_FLAGS_DEBUG}")
    message("-- Building with Flags: ${CMAKE_CXX_FLAGS_DEBUG}")
endif()

set(CMAKE_CXX_FLAGS -pthread)
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/cmake-modules)

add_subdirectory(src)