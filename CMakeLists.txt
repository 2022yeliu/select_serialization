﻿
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

project ("SerializationTool")
include_directories(.)

add_executable (CompareTool "CompareTool.cpp" "data_declaration.h" "cmdline.h")