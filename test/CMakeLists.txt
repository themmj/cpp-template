add_executable(${TEST_BIN_NAME}
    src/main.cpp
)

target_include_directories(${TEST_BIN_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# add gtest
include(${THIRD_PARTY_DIR}/FetchGTest.cmake)

target_link_libraries(${TEST_BIN_NAME}
    PRIVATE
    ${LIB_NAME}
    GTest::gtest
    GTest::gtest_main
)

add_test(
    NAME unit-tests
    COMMAND ${TEST_BIN_NAME}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

add_custom_target(run-tests-for-coverage
    COMMAND ${TEST_BIN_NAME}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

add_custom_target(clean-gcno
    COMMAND find . -name "\"*.gcno\"" -type f -delete
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

add_custom_target(clean-gcda
    COMMAND find . -name "\"*.gcda\"" -type f -delete
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

add_dependencies(run-tests-for-coverage clean-gcda ${TEST_BIN_NAME})

find_program(GCOVR_FOUND gcovr)
if (GCOVR_FOUND)
    add_custom_target(coverage
        COMMAND mkdir -p ${CMAKE_CURRENT_SOURCE_DIR}/coverage
        COMMAND gcovr -r ${CMAKE_SOURCE_DIR} . --html --html-details -o ${CMAKE_CURRENT_SOURCE_DIR}/coverage/coverage.html --gcov-executable ${GCOVEXEC}
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/src
    )
    add_dependencies(coverage run-tests-for-coverage)
else()
    message(WARNING "gcovr not found, coverage target will not be available")
endif()
