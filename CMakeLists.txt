cmake_minimum_required(VERSION 3.0)

project(Regexpr)

add_executable(Regexpr Regexpr.cpp Word.cpp Regular_expression_analysis.cpp)

add_executable(Regexpr_test test.cpp run_tests.cpp)
target_link_libraries(Regexpr_test ${GTEST_LIBRARIES} Threads::Threads)