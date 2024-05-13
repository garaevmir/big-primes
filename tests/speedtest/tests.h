#pragma once

#include "defines.h"
#include "test_miller_ryabin.h"
#include "test_lucas_primality.h"
#include "test_trial_division.h"
#include "test_pollard_rho.h"
#include "test_quadratic_sieve.h"
#include <chrono>
#include "math_functions.h"

template <typename T>
void time_measure(const T& function, const BigPrimes::LongInt& number) {
    BigPrimes::SmallType digits = BigPrimes::Maths::number_of_digits(number);
    auto func = function;
    auto start = std::chrono::high_resolution_clock::now();
    auto output = func(number);
    auto end = std::chrono::high_resolution_clock::now();
    auto time_elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Time consumed for " << digits <<" digit number: " << time_elapsed.count() << " ms\n";
}
