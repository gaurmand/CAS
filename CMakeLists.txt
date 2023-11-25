cmake_minimum_required(VERSION 3.14)
project(CAS)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Werror")

include_directories("include")

enable_testing()
include(GoogleTest)
add_subdirectory(src)
add_subdirectory(tests)
