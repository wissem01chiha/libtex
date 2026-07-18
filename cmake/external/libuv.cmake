find_package(LibUV QUIET)
if(LibUV_FOUND)
    message(STATUS "LibUV found: ${LibUV_INCLUDE_DIRS}")
    include_directories(SYSTEM ${LibUV_INCLUDE_DIRS})
else()
    message(STATUS "LibUV not found. Downloading and building from source...")
    include(FetchContent)
    FetchContent_Declare(
        LibUV
        URL https://github.com/libuv/libuv/archive/refs/tags/v1.52.1.zip
    )
    FetchContent_MakeAvailable(LibUV)
    set(LibUV_INCLUDE_DIRS ${LibUV_SOURCE_DIR}/src)
    include_directories(SYSTEM ${LibUV_INCLUDE_DIRS})
endif()