#pragma once

#include "defines.h"
#include "test_miller_ryabin.h"
#include "test_lucas_primality.h"
#include "test_trial_division.h"
#include "test_pollard_rho.h"
#include "test_quadratic_sieve.h"
#include <chrono>

template <typename T>
void time_measure(const T& function, const BigPrimes::LongInt& number) {
    BigPrimes::SmallType digits = 0;
    BigPrimes::LongInt temp = number;
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
