cmake_minimum_required(VERSION 3.16)
project(LogAnalyzer)

set(CMAKE_CXX_STANDARD 17)

add_library(log_analyzer
    src/Parser.cpp
    src/Query.cpp
)

target_include_directories(log_analyzer PUBLIC src)

add_executable(main src/main.cpp)
target_link_libraries(main log_analyzer)

# Tests
enable_testing()
add_subdirectory(tests)