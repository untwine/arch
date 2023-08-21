file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/doc/pxr/arch")

set(DOXYGEN_PROJECT_NAME "Pixar Arch")
set(DOXYGEN_PROJECT_ICON "${PROJECT_SOURCE_DIR}/doc/sphinx/favicon.ico")
set(DOXYGEN_HTML_OUTPUT "doc/pxr/arch/doxygen")
set(DOXYGEN_EXTENSION_MAPPING "h=C++")
set(DOXYGEN_GENERATE_HTML YES)
set(DOXYGEN_GENERATE_LATEX NO)
set(DOXYGEN_GENERATE_TREEVIEW YES)
set(DOXYGEN_QUIET YES)
set(DOXYGEN_SORT_MEMBER_DOCS NO)
set(DOXYGEN_FULL_PATH_NAMES NO)
set(DOXYGEN_FILE_PATTERNS *.dox *.h)
set(DOXYGEN_ALWAYS_DETAILED_SEC YES)
set(DOXYGEN_JAVADOC_AUTOBRIEF YES)
set(DOXYGEN_BUILTIN_STL_SUPPORT YES)
set(DOXYGEN_INLINE_SIMPLE_STRUCTS YES)
set(DOXYGEN_PREDEFINED doxygen)
set(DOXYGEN_QUIET YES)
set(DOXYGEN_EXTRACT_ALL YES)
set(DOXYGEN_WARN_IF_DOC_ERROR NO)
set(DOXYGEN_EXCLUDE
    "${PROJECT_SOURCE_DIR}/src/pxr/arch/api.h"
    "${PROJECT_SOURCE_DIR}/src/pxr/arch/pch.h"
)
set(DOXYGEN_GENERATE_TAGFILE
    "${CMAKE_CURRENT_BINARY_DIR}/doc/pxr/arch/pxr-arch.tag")

doxygen_add_docs(archApiRefDoc
    "${PROJECT_SOURCE_DIR}/doc/doxygen/index.dox"
    "${PROJECT_SOURCE_DIR}/doc/doxygen/namespaces.dox"
    "${PROJECT_SOURCE_DIR}/src/pxr/arch"
)

file(COPY sphinx DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
configure_file(sphinx/conf.py sphinx/conf.py @ONLY)

sphinx_add_docs(archDoc
    SOURCE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/sphinx"
    OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/doc/pxr/arch"
    DEPENDS archApiRefDoc
)

add_custom_target(documentation ALL)
add_dependencies(documentation
    archDoc
    archApiRefDoc
)

install(
    DIRECTORY
        "${CMAKE_CURRENT_BINARY_DIR}/doc"
    DESTINATION
        ${CMAKE_INSTALL_PREFIX}
)
