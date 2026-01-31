cmake_minimum_required(VERSION 3.16)
project(cpp_backtracking_puzzles LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---- main demos ----
add_executable(wordle_demo wordle-driver.cpp wordle.cpp dict-eng.cpp)
target_include_directories(wordle_demo PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(sched_demo schedwork-driver.cpp schedwork.cpp)
target_include_directories(sched_demo PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# ---- GoogleTest ----
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(test_hw5
  tests/test_wordle.cpp
  tests/test_schedwork.cpp
  wordle.cpp
  schedwork.cpp
)
target_include_directories(test_hw5 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(test_hw5 PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(test_hw5)
