cmake_minimum_required(VERSION 3.10)

if(POLICY CMP0091)
  cmake_policy(SET CMP0091 NEW) 
endif()
if(POLICY CMP0092)
  cmake_policy(SET CMP0092 NEW)  
endif()

project(libtex LANGUAGES C)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(BUILD_SHARED "Build shared lib" OFF)
option(BUILD_TESTS "Build tests" ON)
option(BUILD_REGRESS "Build regression tests" ON)
option(BUILD_DOC "Build documentation" ON)
option(DO_INSTALL "Install libtex" OFF)
option(ENABLE_COVERAGE "Enable coverage reporting" OFF)
option(BUILD_TOOLS "Build tools in the script directory" ON)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set(sources
    src/figure.c
    src/version.c
    src/document.c
    src/section.c
    src/environment.c
    src/theorem.c
    src/book.c
    src/texutil.c
    src/equation.c
)

set(headers
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

set(tests
    test/document_fs_write_test.c
    test/getusername_test.c
)

set(flags
    -Wall
)

if(MSVC)
    list(APPEND flags
        /W4
    )
endif()

if(BUILD_SHARED)
    add_library(libtex SHARED ${sources})
else()
    add_library(libtex STATIC ${sources})
endif()

target_include_directories(libtex
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_options(libtex PRIVATE ${flags})
target_compile_features(libtex PUBLIC c_std_99)

if(BUILD_TESTS)
    include(CTest)
    enable_testing()
    foreach(testfile ${tests})
        get_filename_component(testname ${testfile} NAME_WE)
        add_executable(${testname} ${testfile})
        add_dependencies(${testname} libtex)
        target_link_libraries(${testname} PRIVATE libtex)
        target_compile_options(${testname} PRIVATE ${flags})
        add_test(NAME ${testname} COMMAND ${testname})
    endforeach()
endif()

if(ENABLE_COVERAGE)
  find_program(LCOV lcov REQUIRED)
  find_program(GENHTML genhtml REQUIRED)
endif()


if(DO_INSTALL)

  
endif()