cmake_minimum_required(VERSION 3.13)
project(Regexpr_analysis)
set(CMAKE_CXX_STANDARD 14)

add_executable(Regexpr_analysis Regexpr.cpp Regexpr.h Regexpr_expression_analysis.cpp Word.cpp Word.h)