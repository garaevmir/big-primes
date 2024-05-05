cmake_minimum_required(VERSION 3.22)
project(big-primes)

find_package(Boost)

include_directories(${Boost_INCLUDE_DIRS})

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif()

include_directories(
        src
        src/qs
)

add_library(
        big-primes-library
        src/math_functions.cpp
        src/pollard-rho.cpp
        src/print_functions.cpp
        src/strong_pseudoprime_test.cpp
        src/test_for_primality.cpp
        src/trial_division.cpp
        src/qs/quadratic_sieve.cpp
        src/qs/linear_algebra.cpp
)

target_link_libraries(
        big-primes-library
        Boost::boost
)

add_subdirectory("tests")
add_subdirectory("speedtest")
add_subdirectory("example")