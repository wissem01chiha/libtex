# SPDX-FileCopyrightText: Copyright (c) 2026, Wissem Chiha
cmake_minimum_required(VERSION 3.12...3.31)

project(libtex LANGUAGES C)

# ============================================================================
# Properties
# ============================================================================
set(PROJECT_VERSION "0.1.0")
set(PROJECT_HOMEPAGE_URL "https://github.com/wissem01chiha/libtex")
set(PROJECT_DESCRIPTION "A C library for writing Latex Tex files.")

# ============================================================================
# CPack
# ============================================================================
set(CPACK_PACKAGE_VENDOR "libtex-project")
set(CPACK_PACKAGE_DESCRIPTION_FILE ${CMAKE_SOURCE_DIR}/README.md)
set(CPACK_RESOURCE_FILE_LICENSE ${CMAKE_SOURCE_DIR}/LICENSE)
set(CPACK_RESOURCE_FILE_README ${CMAKE_SOURCE_DIR}/README.md)
set(CPACK_COMPONENTS_ALL Development Documentation Runtime)

# ============================================================================
# CTest
# ============================================================================
set (CTEST_OUTPUT_ON_FAILURE TRUE)

# ============================================================================
# CMake
# ============================================================================
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_VISIBILITY_PRESET hidden)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

# ============================================================================
# Configuration
# ============================================================================
option(LIBTEX_BUILD_SHARED "Build shared lib" OFF)
option(LIBTEX_BUILD_TESTS "Build tests" ON)
option(LIBTEX_BUILD_REGRESS "Build regression tests" ON)
option(LIBTEX_BUILD_DOC "Build documentation" ON)
option(LIBTEX_INSTALL "Install libtex files" OFF)
option(LIBTEX_ENABLE_COVERAGE "Enable coverage reporting" OFF)
option(LIBTEX_BUILD_TOOLS "Build tools in the script directory" ON)
option(LIBTEX_ASAN "Enable AddressSanitizer (ASan)" OFF)

# ============================================================================
# Build Type
# ============================================================================
get_property(IS_MULTI GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)

if(NOT DEFINED CMAKE_BUILD_TYPE AND NOT IS_MULTI)
    message(STATUS "No CMAKE_BUILD_TYPE set -- using Release")
    set(CMAKE_BUILD_TYPE Release)
endif(NOT DEFINED CMAKE_BUILD_TYPE AND NOT IS_MULTI)

if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/install"
    CACHE PATH "Default install path" FORCE)
endif()

# ============================================================================
# Flags
# ============================================================================

# ============================================================================
# Dependencies
# ============================================================================

# ============================================================================
# Testing
# ============================================================================
if(LIBTEX_BUILD_TESTS)
    include(CTest)
    enable_testing()
endif()

# ============================================================================
# Include Directories
# ============================================================================
list(APPEND libtex_includes
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# ============================================================================
# Source Files
# ============================================================================
set(libtex_sources
    src/figure.c
    src/version.c
    src/document.c
    src/section.c
    src/environment.c
    src/theorem.c
    src/book.c
    src/texutil.c
    src/equation.c
    src/language.c
    src/list.c
)

set(libtex_headers
    include/libtex/figure.h
    include/libtex/theorem.h
    include/libtex/errno.h
    include/libtex/type.h
    include/libtex/version.h
    include/libtex/document.h
    include/libtex/section.h
    include/libtex/environment.h
    include/libtex/book.h
)

set(libtex_test_sources
    test/document_fs_write_test.c
    test/tex_get_username_test.c
)

set(libtex_flags
    -Wall
)

if(MSVC)
    list(APPEND libtex_flags
        /W4
    )
endif()

# ============================================================================
# Configure Files
# ============================================================================
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/texconf.h.in
${PROJECT_BINARY_DIR}/texconf.h)

# ============================================================================
# Targets
# ============================================================================
if(LIBTEX_BUILD_SHARED)
    add_library(${PROJECT_NAME} SHARED ${libtex_sources})
else()
    add_library(${PROJECT_NAME} STATIC ${libtex_sources})
endif()

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_options(${PROJECT_NAME} PRIVATE ${libtex_flags})
target_compile_features(${PROJECT_NAME} PUBLIC c_std_99)

if(LIBTEX_BUILD_TESTS)
    foreach(testfile ${libtex_test_sources})
        get_filename_component(testname ${testfile} NAME_WE)
        add_executable(${testname} ${testfile})
        add_dependencies(${testname} ${PROJECT_NAME})
        target_link_libraries(${testname} PRIVATE ${PROJECT_NAME})
        target_compile_options(${testname} PRIVATE ${libtex_flags})
        add_test(NAME ${testname} COMMAND ${testname})
    endforeach()
endif()

if(LIBTEX_ENABLE_COVERAGE)
  find_program(LCOV lcov REQUIRED)
  find_program(GENHTML genhtml REQUIRED)
endif()

# ============================================================================
# Pkg-Config
# ============================================================================
set(TEX_PC "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.pc")
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}.pc.in
    ${TEX_PC}
    @ONLY
)

# ============================================================================
# Install
# ============================================================================
if(LIBTEX_INSTALL)
    if(LIBTEX_BUILD_SHARED)
        install(
            TARGETS ${PROJECT_NAME}
            COMPONENT Runtime
            EXPORT opcSharedExport
            RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
            ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
            LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
        )
    else()
        install(
            TARGETS ${PROJECT_NAME}
            COMPONENT Runtime
            EXPORT opcStaticExport
            RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
            ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
            LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
        )
    endif()

    install(
        FILES ${libtex_headers}
        COMPONENT Development
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/libtex"
    )

    configure_package_config_file(
        "${PROJECT_SOURCE_DIR}/cmake/tex-config.cmake.in"
        "${PROJECT_BINARY_DIR}/opc-config.cmake"
        INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/libtex
    )

    write_basic_package_version_file(
        "${CMAKE_BINARY_DIR}/libtex-config-version.cmake"
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY SameMajorVersion
    )

    install(
        FILES ${CMAKE_BINARY_DIR}/libtex-config-version.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/libtex
    )
    install(
        FILES ${TEX_PC}
        COMPONENT Development
        DESTINATION "${CMAKE_INSTALL_LIBDIR}/pkgconfig"
    )
    install(
        FILES ${CMAKE_SOURCE_DIR}/LICENSE.txt
        COMPONENT Documentation
        DESTINATION "${CMAKE_INSTALL_DOCDIR}/libtex"
    )
endif()

# ============================================================================
# Package
# ============================================================================
set(CPACK_PACKAGE_VENDOR "Wissem Chiha")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Open Packaging Convention Library")
set(CMAKE_PROJECT_HOMEPAGE_URL "https://github.com/wissem01chiha/libtex")
set(CPACK_RESOURCE_FILE_LICENSE "${PROJECT_SOURCE_DIR}/LICENSE.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
include(CPack)
