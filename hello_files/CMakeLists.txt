cmake_minimum_required(VERSION 4.1)
project(hello_world)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED 23)

add_executable(hello)
target_sources(hello PRIVATE
    main.cpp
PRIVATE
FILE_SET CXX_MODULES
FILES
    my_module.cpp
)
