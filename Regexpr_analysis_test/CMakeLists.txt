make_minimum_required(VERSION 3.13)
project(Regexpr_test)
enable_testing()
set(CMAKE_CXX_STANDARD 14)

find_package(GTest REQUIRED)

SET(CMAKE_CXX_FLAGS -pthread)
enable_testing()

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(Regexpr_test test.cpp run_tests.cpp Regexpr.cpp Regexpr.h Word.cpp Word.h)
target_link_libraries(Regexpr_test ${GTEST_LIBRARIES})
add_test(NAME Test COMMAND Regexpr_test)