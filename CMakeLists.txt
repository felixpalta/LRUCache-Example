cmake_minimum_required(VERSION 2.8)

project(LruCache)

add_subdirectory(./googletest)

add_library(muhlib "lib.cpp")
add_executable(${PROJECT_NAME} "main.cpp")
add_executable(tests_default tests_default.cpp)

set_target_properties(${PROJECT_NAME} muhlib tests_default PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    muhlib
)
target_link_libraries(tests_default PRIVATE
    gtest_main
    muhlib
)

enable_testing()

add_test(tests_default tests_default)
