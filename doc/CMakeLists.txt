find_program(DOT_FOUND dot)
if (DOT_FOUND)
    set(HAVE_DOT "YES")
else()
    set(HAVE_DOT "NO")
endif()

find_package(Doxygen)
if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ${PROJECT_SOURCE_DIR}/doc/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    # note the option ALL which allows to build the docs together with the application
    add_custom_target( doc_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM )
else ()
  message("Doxygen needs to be installed to generate the doxygen documentation")
endif ()

find_program(HPP2PUML_FOUND hpp2plantuml)
if (HPP2PUML_FOUND)
    set(PUML_DIR ${CMAKE_SOURCE_DIR}/doc/puml)
    add_custom_target(doc_puml ALL
        COMMAND mkdir -p ${PUML_DIR}
        COMMAND hpp2plantuml -i "src/**/*.hpp" -o ${PUML_DIR}/output.puml
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    )
else()
    message("hpp2plantuml needs to be installed to generate PUML of the codebase")
endif()

