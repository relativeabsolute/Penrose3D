cmake_minimum_required(VERSION 3.0)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_COLOR_MAKEFILE ON)

if(WIN32)
    set(CMAKE_SHARED_LIBRARY_PREFIX "")
endif()

add_subdirectory(components/PenroseEngine)
add_subdirectory(components/PenroseRun)
