cmake_minimum_required(VERSION 3.0)

project(PenroseRun)

file(GLOB PENROSE_RUN_SRCS src/*.cpp)

include_directories(${PenroseEngine_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${PENROSE_RUN_SRCS})

target_link_libraries(${PROJECT_NAME} PenroseEngine)
