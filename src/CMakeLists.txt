cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

#Exception Handling
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/compiled-executables)

project(abs-value-compiletime)
file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.h ${CMAKE_CURRENT_SOURCE_DIR}/abs-value-compiletime.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})

find_package(NanoLog REQUIRED)
target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${Nanolog_INCLUDE_DIR})
target_link_directories(${PROJECT_NAME} PUBLIC ${Nanolog_LIB_DIR})
add_dependencies(${PROJECT_NAME} NanoLog)
target_link_libraries(${PROJECT_NAME} PRIVATE NanoLog)

target_link_libraries(${PROJECT_NAME} PRIVATE rt)

#------------------------------------------------------------------------------------
project(abs-value-runtime)
file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.h ${CMAKE_CURRENT_SOURCE_DIR}/abs-value-runtime.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${Nanolog_INCLUDE_DIR})
target_link_directories(${PROJECT_NAME} PUBLIC ${Nanolog_LIB_DIR})
add_dependencies(${PROJECT_NAME} NanoLog)
target_link_libraries(${PROJECT_NAME} PRIVATE NanoLog)

target_link_libraries(${PROJECT_NAME} PRIVATE rt)