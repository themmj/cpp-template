set (SRC_FILES
    main.cpp
    math/math.cpp
)

set (INCL_DIRS
    ${CMAKE_SOURCE_DIR}/third-party/spdlog/include
)

add_executable(${BINARY} ${SRC_FILES})

set_target_properties(
    ${BINARY} PROPERTIES

    # set output to bin dir
    RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR}
)
target_include_directories(${BINARY} PUBLIC
    ${INCL_DIRS}
)

add_library(${BINARY}-lib STATIC EXCLUDE_FROM_ALL ${SRC_FILES})

target_compile_options(${BINARY}-lib PUBLIC
    -O0
    --coverage
)
target_include_directories(${BINARY}-lib PUBLIC
    ${INCL_DIRS}
)

add_custom_target(run
    COMMAND ${BIN_DIR}/${BINARY}
)

add_dependencies(run ${BINARY})

