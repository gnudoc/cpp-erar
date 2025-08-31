cmake_minimum_required(VERSION 4.1)
project(crash_course)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED 23)

add_executable(hello)
target_sources(hello PRIVATE 
    main.cpp
)

target_compile_options(hello PRIVATE 
    -Werror
    -Wall
    -Wextra
    -Wconversion
    -Wshadow
)