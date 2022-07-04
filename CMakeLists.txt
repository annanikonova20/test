cmake_minimum_required(VERSION 3.5)

project(first LANGUAGES CXX)


find_package(Qt5Test REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing()

add_executable(first
    tst_first.cpp
    dfpostcore_export.h
    dfpoststring.cpp
    dfpoststring.h
)

add_test(NAME first COMMAND first)

target_link_libraries(first PRIVATE Qt5::Test)

