cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

project(io_32bit)

include_directories(../..)
add_library(io_32bit SHARED
        ../dll.cc
)

set_target_properties(io_32bit PROPERTIES OUTPUT_NAME "chuniio_xr_x86")

# TODO: delete this
set_target_properties(io_32bit PROPERTIES RUNTIME_OUTPUT_DIRECTORY "D:/Games/CHUNITHM LUMINOUS PLUS (2.26)/bin")

install(TARGETS io_32bit
        # DLLs go to bin dir (RUNTIME)
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        # Import libs (.lib for MSVC) go to lib dir (LIBRARY)
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        # Static libs (.lib for MSVC) go to lib dir (ARCHIVE)
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)