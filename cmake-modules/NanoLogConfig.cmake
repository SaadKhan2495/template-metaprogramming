include(ExternalProject)

if(NOT TARGET Nanolog_project)
ExternalProject_Add(Nanolog_project
GIT_REPOSITORY https://github.com/PlatformLab/NanoLog.git
PREFIX ${CMAKE_CURRENT_BINARY_DIR}/NanoLog
BUILD_IN_SOURCE 1
CONFIGURE_COMMAND ""
BUILD_COMMAND cd runtime && $(MAKE)
INSTALL_COMMAND ""
)
endif()

ExternalProject_Get_Property(Nanolog_project SOURCE_DIR)

set(Nanolog_INCLUDE_DIR ${SOURCE_DIR}/runtime) 
set(Nanolog_LIB_DIR ${SOURCE_DIR}/runtime) 

add_library(NanoLog STATIC IMPORTED)

set_property(TARGET NanoLog PROPERTY IMPORTED_LOCATION ${Nanolog_LIB_DIR}/libNanoLog.a)
add_dependencies(NanoLog Nanolog_project)