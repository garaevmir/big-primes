#pragma once

#include "defines.h"
#include "test_miller_ryabin.h"
#include "test_lucas_primality.h"
#include "test_trial_division.h"
#include "test_pollard_rho.h"
#include "test_quadratic_sieve.h"
#include <chrono>

//void primality_test_time_measure(const primality_function& function, const project::LongInt& number);

template <typename T>
void time_measure(const T& function, const project::LongInt& number) {
    project::SmallType digits = 0;
    project::LongInt temp = number;
    auto func = function;
    while (temp > 0) {
        ++digits;
        temp /= 10;
    }
    auto start = std::chrono::high_resolution_clock::now();
    auto output = func(number);
    auto end = std::chrono::high_resolution_clock::now();
    auto time_elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Time consumed for " << digits <<" digit number: " << time_elapsed.count() << " ms\n";
}
