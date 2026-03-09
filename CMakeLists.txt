cmake_minimum_required(VERSION 3.28.5)
project(gcc15_modules_test LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "-g -Wall -Wextra -Wpedantic -pedantic-errors -Werror -Wfatal-errors -Wno-psabi")

include_directories(BEFORE ${PROJECT_SOURCE_DIR})

add_executable(main main.cpp)
target_sources(main PUBLIC FILE_SET CXX_MODULES BASE_DIRS ${PROJECT_SOURCE_DIR}
  FILES
  ${PROJECT_SOURCE_DIR}/test1.cppm
  ${PROJECT_SOURCE_DIR}/tools.cppm
)
