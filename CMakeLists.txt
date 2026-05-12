cmake_minimum_required(VERSION 3.10)

project(libtex LANGUAGES C)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(LIBTEX_BUILD_SHARED "Build shared lib" OFF)
option(LIBTEX_BUILD_TESTS "Build tests" ON)
option(LIBTEX_BUILD_REGRESS "Build regression tests" ON)
option(LIBTEX_BUILD_DOC "Build documentation" ON)
option(LIBTEX_DO_INSTALL "Install libtex" OFF)
option(LIBTEX_ENABLE_COVERAGE "Enable coverage reporting" OFF)
option(LIBTEX_BUILD_TOOLS "Build tools in the script directory" ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

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

if(LIBTEX_BUILD_SHARED)
    add_library(${PROJECT_NAME} SHARED ${sources})
else()
    add_library(${PROJECT_NAME} STATIC ${sources})
endif()

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_options(${PROJECT_NAME} PRIVATE ${flags})
target_compile_features(${PROJECT_NAME} PUBLIC c_std_99)

if(LIBTEX_BUILD_TESTS)
    include(CTest)
    enable_testing()
    foreach(testfile ${tests})
        get_filename_component(testname ${testfile} NAME_WE)
        add_executable(${testname} ${testfile})
        add_dependencies(${testname} ${PROJECT_NAME})
        target_link_libraries(${testname} PRIVATE ${PROJECT_NAME})
        target_compile_options(${testname} PRIVATE ${flags})
        add_test(NAME ${testname} COMMAND ${testname})
    endforeach()
endif()

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/texconf.h.in ${PROJECT_BINARY_DIR}/texconf.h)

if(LIBTEX_ENABLE_COVERAGE)
  find_program(LCOV lcov REQUIRED)
  find_program(GENHTML genhtml REQUIRED)
endif()


if(LIBTEX_DO_INSTALL)

  
endif()