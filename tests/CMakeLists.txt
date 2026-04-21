find_package(GTest REQUIRED)

add_executable(log_tests test.cpp)

target_link_libraries(log_tests
    log_analyzer
    GTest::gtest
    GTest::gtest_main
)

include(GoogleTest)
add_test(NAME log_tests COMMAND log_tests)