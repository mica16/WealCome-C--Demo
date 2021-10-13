project(tests)
add_subdirectory(lib)
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

# adding the tests_run target
add_executable(tests_run PalindromeTest.cpp)

# linking Gtests_run which will be tested
target_link_libraries(tests_run src)
target_link_libraries(tests_run gmock gmock_main)