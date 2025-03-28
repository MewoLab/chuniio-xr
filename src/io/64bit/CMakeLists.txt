cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

project(io_64bit)

include_directories(../..)
add_library(io_64bit SHARED
        ../dll.cc
)

set_target_properties(io_64bit PROPERTIES OUTPUT_NAME "chuniio_xr_x64")

# TODO: delete this
set_target_properties(io_64bit PROPERTIES RUNTIME_OUTPUT_DIRECTORY "D:/Games/CHUNITHM LUMINOUS PLUS (2.26)/bin")
