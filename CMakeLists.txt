cmake_minimum_required(VERSION 3.30)
project(chunixr_io)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_library(chunixr_io SHARED
        src/xr/led_pipe.cc
        src/xr/dll.cc
)
set_target_properties(chunixr_io PROPERTIES RUNTIME_OUTPUT_DIRECTORY "%userprofile%/chunibyo/Assets/io")