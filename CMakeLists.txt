cmake_minimum_required(VERSION 3.24)
project(CYK)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0 -Wall -fprofile-arcs -ftest-coverage")

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(CYK main.cpp Grammar.h Tests.cpp)

target_link_libraries(CYK ${GTEST_LIBRARIES} Threads::Threads)

enable_testing()
add_test(CYK "./CYK")