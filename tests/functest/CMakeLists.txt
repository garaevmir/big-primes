cmake_minimum_required(VERSION 3.14)
project(test_big_primes)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

add_executable(
        test
        test_miller_ryabin.cpp
        test_lucas.cpp
        test_trial_division.cpp
        test_pollard_rho.cpp
        test_quadratic_sieve.cpp
)
target_link_libraries(
        test
        big-primes-library
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test)