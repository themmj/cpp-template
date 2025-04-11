cmake_minimum_required(VERSION 3.10)

project(cpp-template VERSION 0.0.1)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(BUILD_TESTS "Build tests" OFF)

set(BIN_NAME ${PROJECT_NAME})
set(LIB_NAME ${BIN_NAME}-static)
set(THIRD_PARTY_DIR ${CMAKE_SOURCE_DIR}/third-party)

# coverage settings
if (NOT DEFINED GCOVEXEC)
    SET(GCOVEXEC gcov) # binary
endif()
set(COVERAGE_LIB gcov) # TODO don't restrict to gcc toolchain
set(COVERAGE_COMPILE_OPTIONS -fprofile-arcs -ftest-coverage)
set(COVERAGE_LINK_OPTIONS --coverage)

# core code
add_subdirectory(src)

if(${BUILD_TESTS})
    # tests
    set(TEST_BIN_NAME ${BIN_NAME}-test)
    list(APPEND CMAKE_CTEST_ARGUMENTS "--verbose")
    enable_testing()
    add_subdirectory(test)
endif()

