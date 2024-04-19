cmake_minimum_required(VERSION 3.22)
project(big-primes)

find_package(Boost 1.85.0)

include_directories(${Boost_INCLUDE_DIRS})

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif()

include_directories(
        src
        src/qs
)

add_library(
        big-primes
        src/math_functions.cpp
        src/pollard-rho.cpp
        src/print_functions.cpp
        src/strong_pseudoprime_test.cpp
        src/test_for_primality.cpp
        src/trial_division.cpp
        src/qs/quadratic_sieve.cpp
        src/qs/congruences.cpp
        src/qs/linear_algebra.cpp
)

target_link_libraries(big-primes Boost::boost)

add_executable(test src/main.cpp)

target_link_libraries(test big-primes)