cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

project(io_32bit)

include_directories(../..)
add_library(io_32bit SHARED
        ../dll.cc
)

set_target_properties(io_32bit PROPERTIES OUTPUT_NAME "chuniio_xr_x86")

# TODO: delete
set_target_properties(io_32bit PROPERTIES RUNTIME_OUTPUT_DIRECTORY "D:/Games/CHUNITHM LUMINOUS PLUS (2.26)/bin")

install(TARGETS io_32bit
        RUNTIME DESTINATION ${RUNTIME_OUTPUT_DIRECTORY}
        LIBRARY DESTINATION ${RUNTIME_OUTPUT_DIRECTORY}
        ARCHIVE DESTINATION ${RUNTIME_OUTPUT_DIRECTORY}
)