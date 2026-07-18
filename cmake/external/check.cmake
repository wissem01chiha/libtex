find_package(Check QUIET)
if(CHECK_FOUND)
    message(STATUS "Check found: ${CHECK_INCLUDE_DIR}")
    include_directories(SYSTEM ${CHECK_INCLUDE_DIR})
else()
    message(STATUS "Check not found. Downloading and building from source...")
    include(FetchContent)
    FetchContent_Declare(
        Check
        URL https://github.com/libcheck/check/archive/refs/tags/0.15.2.zip
    )
    FetchContent_MakeAvailable(Check)
    set(CHECK_INCLUDE_DIR ${Check_SOURCE_DIR}/src ${Check_BINARY_DIR}/src ${Check_BINARY_DIR})
    include_directories(SYSTEM ${CHECK_INCLUDE_DIR})
endif()
