cmake_minimum_required(VERSION 3.13)
project(Regexpr_with_test)
set(CMAKE_CXX_STANDARD 14)

include_directories(Regexpr_analysis)
add_subdirectory(Regexpr_analysis)
add_subdirectory(Regexpr_analysis_test)