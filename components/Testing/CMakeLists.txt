cmake_minimum_required(VERSION 3.0)
project(Testing CXX)

file(GLOB ${PROJECT_NAME}_SRCS *.cpp)

find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)

include_directories(${PenroseMath_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})

add_definitions(-DBOOST_TEST_DYN_LINK)
add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SRCS})
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
target_link_libraries(${PROJECT_NAME} ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_SYSTEM_LIBRARY} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
    PenroseMath)
