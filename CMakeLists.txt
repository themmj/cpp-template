cmake_minimum_required(VERSION 3.10)

project(example-project)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CXX_EXTENSIONS OFF)

option(BUILD_DOC "Build documentation" ON)
option(BUILD_TESTS "Build tests" ON)

set(BINARY example)
set(BIN_DIR ${CMAKE_SOURCE_DIR}/bin)

add_subdirectory(src)

if(${BUILD_DOC})
    add_subdirectory(doc)
endif()

if(${BUILD_TESTS})
    add_subdirectory(test)
endif()
