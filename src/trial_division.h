#pragma once

#include "defines.h"

namespace project {
    struct TrialDivision {
        public:
            TrialDivision(const LongInt& number) {
                number_to_factorize = number;
            }
            //bool is_prime();
            std::vector<factorization> factorize();
        private:
            LongInt border_for_divisor(const LongInt& number);
            LongInt factor_one(LongInt& start);
            SmallType find_degree(const LongInt& factor);
            void factor_out_2();
            LongInt number_to_factorize;
            std::vector<factorization> factors;
    };
}
