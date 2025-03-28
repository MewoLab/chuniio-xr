cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

project(chunixr)

set(WIN32_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/Win32.cmake)

# 32-bit (chusan)

include(ExternalProject)
ExternalProject_Add(
        io_32bit_external
        SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/io/32bit
        CMAKE_ARGS
            -DCMAKE_TOOLCHAIN_FILE=${WIN32_TOOLCHAIN_FILE}
            -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_CURRENT_BINARY_DIR}/install_32
            -DCMAKE_BUILD_TYPE=$<CONFIG>
        BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/32bit-build
        #INSTALL_COMMAND ${CMAKE_COMMAND} --build . --target install --config $<CONFIG>
)
