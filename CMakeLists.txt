cmake_minimum_required(VERSION 3.30)
project(chunixr_io)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_library(chunixr_io SHARED
        src/led_pipe.cc
        src/dll.cc
)
