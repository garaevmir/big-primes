#pragma once

#include "defines.h"

namespace project {
    struct TrialDivision {
        public:
            static std::vector<factorization> factorize(const LongInt& number);
        private:
            static LongInt border_for_divisor(const LongInt& number);
            static LongInt factor_one(const LongInt& number_to_factorise, LongInt& start);
            static SmallType find_degree(LongInt& number_to_factorise, const LongInt& factor);
            static std::vector<factorization> factor_out_2(LongInt& number_to_factorise);
    };
}
