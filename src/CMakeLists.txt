# sources
set(SRC_FILES
    log.cpp
)

# add spdlog
include(${THIRD_PARTY_DIR}/FetchSpdlog.cmake)

add_library(${LIB_NAME} STATIC ${SRC_FILES})

target_include_directories(${LIB_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${THIRD_PARTY_DIR}/spdlog/include
)

target_link_libraries(${LIB_NAME}
    PUBLIC
    spdlog::spdlog
    PRIVATE
    $<$<CONFIG:Debug>:${COVERAGE_LIB}>
)

target_compile_definitions(${LIB_NAME}
    PUBLIC
    $<$<CONFIG:Debug>:DEBUG_BUILD>
)

target_compile_options(${LIB_NAME}
    PUBLIC
    -Wall
    -Werror
    -Wextra
    -Wpedantic
    -Wconversion
    -Wcast-align
    -Wunused
    -Wshadow
    PRIVATE
    $<$<CONFIG:Debug>:${COVERAGE_COMPILE_OPTIONS}>
)

target_link_options(${LIB_NAME}
    PRIVATE
    $<$<CONFIG:Debug>:${COVERAGE_LINK_OPTIONS}>
)

add_executable(${BIN_NAME} main.cpp)

target_link_libraries(${BIN_NAME}
    PRIVATE
    ${LIB_NAME}
)

add_custom_target(run
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${BIN_NAME}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

add_dependencies(run ${BIN_NAME})
