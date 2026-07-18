# SPDX-FileCopyrightText: Copyright (c) 2026, Wissem Chiha
cmake_minimum_required(VERSION 3.12...3.31)

project(tex LANGUAGES C)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

include(CMakePackageConfigHelpers)
include(CMakeDependentOption)
include(CheckCCompilerFlag)
include(GNUInstallDirs)
include(CTest)

set(PROJECT_VERSION "0.1.0")
set(PROJECT_HOMEPAGE_URL "https://github.com/wissem01chiha/libtex")
set(PROJECT_DESCRIPTION "A C library for writing Latex Tex files.")

set(CPACK_PACKAGE_VENDOR "libtex")
set(CPACK_PACKAGE_DESCRIPTION_FILE ${CMAKE_SOURCE_DIR}/README.md)
set(CPACK_RESOURCE_FILE_LICENSE ${CMAKE_SOURCE_DIR}/LICENSE.md)
set(CPACK_RESOURCE_FILE_README ${CMAKE_SOURCE_DIR}/README.md)
set(CPACK_COMPONENTS_ALL Development Documentation Runtime)

set(CTEST_OUTPUT_ON_FAILURE TRUE)
set(CMAKE_C_VISIBILITY_PRESET hidden)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)
set(CMAKE_C_STANDARD 11)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_SUPPRESS_DEVELOPER_WARNINGS ON)
set(CMAKE_WARN_DEPRECATED OFF CACHE BOOL "suppress cmake deprecation message")

option(LIBTEX_BUILD_SHARED "Build shared lib" OFF)
option(LIBTEX_BUILD_TESTS "Build tests" ON)
option(LIBTEX_BUILD_REGRESS "Build regression tests" ON)
option(LIBTEX_BUILD_DOC "Build documentation" ON)
option(LIBTEX_INSTALL "Install libtex files" OFF)
option(LIBTEX_ENABLE_COVERAGE "Enable coverage reporting" OFF)
option(LIBTEX_BUILD_TOOLS "Build tools in the script directory" ON)
option(LIBTEX_ASAN "Enable AddressSanitizer (ASan)" OFF)

if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/install"
    CACHE PATH "default install path" FORCE)
endif()

include(external/libuv)
if(LIBTEX_BUILD_TESTS)
    include(external/check)
endif()

list(APPEND tex_includes
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set(tex_sources
    src/algorithm.c
    src/article.c
    src/bibliography.c
    src/book.c
    src/document.c
    src/environment.c
    src/equation.c
    src/figure.c
    src/language.c
    src/list.c
    src/section.c
    src/table.c
    src/get_date.c
    src/get_time.c
    src/theorem.c
    src/version.c
)

if(WIN32)
    list(APPEND tex_sources
        src/win/get_username.c
        src/win/tex_strdup.c
    )
else()
    list(APPEND tex_sources
        src/unix/get_username.c
        src/unix/tex_strdup.c
    )
endif() 

set(tex_test_sources
    test/test_document_fs_write.c
    test/test_document_api.c
    test/test_get_username.c
    test/test_document_add_fs_content.c
)

set(tex_flags
    -Wall
)

if(MSVC)
    list(APPEND tex_flags
        /W4
    )
endif()

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/texconf.h.in
${PROJECT_BINARY_DIR}/texconf.h)

if(LIBTEX_BUILD_SHARED)
    add_library(${PROJECT_NAME} SHARED ${tex_sources})
else()
    add_library(${PROJECT_NAME} STATIC ${tex_sources})
endif()

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)
target_link_libraries(${PROJECT_NAME} PUBLIC uv_a)
target_compile_options(${PROJECT_NAME} PRIVATE ${tex_flags})

if(LIBTEX_BUILD_TOOLS)
    add_executable(tex2pdf tools/tex2pdf.c)
    target_link_libraries(tex2pdf PUBLIC ${PROJECT_NAME})
    add_dependencies(tex2pdf ${PROJECT_NAME})
endif()

if(LIBTEX_BUILD_TESTS)
    enable_testing()
    foreach(testfile ${tex_test_sources})
        get_filename_component(testname ${testfile} NAME_WE)
        add_executable(${testname} ${testfile})
        add_dependencies(${testname} ${PROJECT_NAME})
        target_link_libraries(${testname} PRIVATE ${PROJECT_NAME} compat check)
        target_compile_options(${testname} PRIVATE ${tex_flags})
        add_test(NAME ${testname} COMMAND ${testname})
    endforeach()
endif()

if(LIBTEX_ENABLE_COVERAGE)
  find_program(LCOV lcov REQUIRED)
  find_program(GENHTML genhtml REQUIRED)
endif()

set(tex_pc "${CMAKE_CURRENT_BINARY_DIR}/tex.pc")
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/tex.pc.in
    ${tex_pc}
    @ONLY
)

if(LIBTEX_INSTALL)
    if(LIBTEX_BUILD_SHARED)
        install(
            TARGETS ${PROJECT_NAME}
            COMPONENT Runtime
            EXPORT texSharedExport
            RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
            ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
            LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
        )
    else()
        install(
            TARGETS ${PROJECT_NAME}
            COMPONENT Runtime
            EXPORT texStaticExport
            RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
            ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
            LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
        )
    endif()

    install(
        FILES ${tex_headers}
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
        FILES ${tex_pc}
        COMPONENT Development
        DESTINATION "${CMAKE_INSTALL_LIBDIR}/pkgconfig"
    )
    install(
        FILES ${CMAKE_SOURCE_DIR}/LICENSE.md
        COMPONENT Documentation
        DESTINATION "${CMAKE_INSTALL_DOCDIR}/libtex"
    )
endif()

set(CPACK_PACKAGE_VENDOR "Wissem Chiha")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "A C library for writing Latex Tex files.")
set(CMAKE_PROJECT_HOMEPAGE_URL "https://github.com/wissem01chiha/libtex")
set(CPACK_RESOURCE_FILE_LICENSE "${PROJECT_SOURCE_DIR}/LICENSE.md")
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
include(CPack)
