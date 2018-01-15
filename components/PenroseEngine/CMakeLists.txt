cmake_minimum_required(VERSION 3.0)
project(PenroseEngine CXX)

file(GLOB ${PROJECT_NAME}_SRCS src/*.cpp)

add_library(${PROJECT_NAME} SHARED ${${PROJECT_NAME}_SRCS})
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

find_package(SDL2 REQUIRED)
# findopengl()
include(FindGLEW)

include_directories(${SDL2_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/include
    ${GLEW_INCLUDE_DIRS} ${PenroseMath_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES}
    ${GLEW_LIBRARIES} PenroseMath)

set(${PROJECT_NAME}_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/include
    ${SDL2_INCLUDE_DIRS}
    CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)
