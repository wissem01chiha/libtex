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

option(LIBTEX_BUILD_SHARED "Build shared lib" OFF)
option(LIBTEX_BUILD_TESTS "Build tests" ON)
option(LIBTEX_BUILD_EXAMPLES "Build examples" ON)
option(LIBTEX_BUILD_DOC "Build documentation" ON)
option(LIBTEX_DO_INSTALL "Install libtex" OFF)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set(tex_sources
    src/figure.c
    src/version.c
    src/document.c
    src/section.c
    src/environment.c
)

set(tex_headers
    include/libtex/figure.h
    include/libtex/theorem.h
    include/libtex/errno.h
    include/libtex/type.h
    include/libtex/version.h
)

set(tex_flags
    -Wall
)

if(MSVC)
    list(APPEND tex_flags
        /W4
    )
endif()

if(LIBTEX_BUILD_SHARED)
    add_library(libtex SHARED ${tex_sources})
else()
    add_library(libtex STATIC ${tex_sources})
endif()

target_include_directories(libtex
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_options(libtex PRIVATE ${tex_flags})
target_compile_features(libtex PUBLIC c_std_99)

if(LIBTEX_BUILD_TESTS)
    include(CTest)
    enable_testing()
endif()

if(LIBTEX_BUILD_EXAMPLES)
     
endif()

if(LIBTEX_DO_INSTALL)

    include(GNUInstallDirs)
    set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/install CACHE PATH "Install path" FORCE)
    install(TARGETS libtex
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
    )

    install(DIRECTORY include/ DESTINATION include)

    set(CPACK_PROJECT_NAME ${PROJECT_NAME})
    set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
    set(CPACK_GENERATOR "DEB")
    set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Wissem Chiha") 
    set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
    set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6 (>= 2.4)")
    set(CPACK_DEBIAN_PACKAGE_SECTION "libs")
    set(CPACK_DEBIAN_PACKAGE_DESCRIPTION "LIBTEX – C Library for Generating LaTeX TEX Documents")  
    set(CPACK_DEBIAN_PACKAGE_HOMEPAGE "https://github.com/wissem01chiha/libtex")  
    set(CPACK_DEBIAN_PACKAGE_PRIORITY "optional") 

    include(CPack)

endif()