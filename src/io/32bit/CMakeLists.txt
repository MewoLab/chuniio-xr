cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

project(io_32bit)

include_directories(../..)
add_library(io_32bit SHARED
        ../dll.cc
)

set_target_properties(io_32bit PROPERTIES OUTPUT_NAME "chuniio_xr_x32")

# TODO: delete this
set_target_properties(io_32bit PROPERTIES RUNTIME_OUTPUT_DIRECTORY "D:/Games/CHUNITHM LUMINOUS PLUS (2.26)/bin")

install(TARGETS io_32bit
        # DLLs go to bin dir (RUNTIME)
        RUNTIME DESTINATION ${RUNTIME_OUTPUT_DIRECTORY}
        # Import libs (.lib for MSVC) go to lib dir (LIBRARY)
        LIBRARY DESTINATION ${RUNTIME_OUTPUT_DIRECTORY}
        # Static libs (.lib for MSVC) go to lib dir (ARCHIVE)
        ARCHIVE DESTINATION ${RUNTIME_OUTPUT_DIRECTORY}
)