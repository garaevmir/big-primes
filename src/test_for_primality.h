#pragma once

#include "defines.h"
#include "trial_division.h"
#include "math_functions.h"

namespace project {

    struct LucasPrimalityTest {
        public:
            static bool is_prime(const LongInt& number_to_test);
        private:
            static LongInt computing_border(const LongInt& number_to_test);
            static bool run_factors(const LongInt& number_to_test, LongInt& temp, const LongInt& arg,
                             const std::vector<factorization>& factors);
            static bool testing(const LongInt& number_to_test, const LongInt& arg,
                         const std::vector<factorization>& factorization);
    };

}
