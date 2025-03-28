cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

project(unity)

include_directories(..)
add_library(unity SHARED
        dll.cc
        led_pipe.cc
)

set_target_properties(unity PROPERTIES OUTPUT_NAME "chunixr")

# TODO: remove this
set_target_properties(unity PROPERTIES RUNTIME_OUTPUT_DIRECTORY "$ENV{userprofile}/chunibyo/Assets/io")