cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

project(chunixr)

# 32-bit (chusan)

include(ExternalProject)
ExternalProject_Add(
        io_32bit_external
        SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/io/32bit
        CMAKE_ARGS
            -A Win32
            -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_CURRENT_BINARY_DIR}/install_32
        BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/32bit-build
        INSTALL_COMMAND ${CMAKE_COMMAND} --build . --target install --config $<CONFIG>
        BUILD_ALWAYS TRUE
)

# 64-bit (amdaemon)

add_subdirectory(src/io/64bit)

# Unity DLL

add_subdirectory(src/unity)