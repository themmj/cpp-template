set (SRC_FILES
    main.cpp
    math/math.cpp
)

add_executable(${BINARY} ${SRC_FILES})

set_target_properties(
    ${BINARY} PROPERTIES

    # set output to bin dir
    RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR}
)

add_library(${BINARY}-lib STATIC EXCLUDE_FROM_ALL ${SRC_FILES})

target_compile_options(${BINARY}-lib PUBLIC
    -O0
    --coverage
)

add_custom_target(run
    COMMAND ${BIN_DIR}/${BINARY}
)

add_dependencies(run ${BINARY})
