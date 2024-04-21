#pragma once

#include "defines.h"
#include "strong_pseudoprime_test.h"

namespace project {
    struct TrialDivision {
        public:
            static std::map<LongInt, SmallType> factorize(const LongInt& number);
        private:
            static LongInt border_for_divisor(const LongInt& number);
            static LongInt factor_one(const LongInt& number_to_factorise, LongInt& start);
            static SmallType find_degree(LongInt& number_to_factorise, const LongInt& factor);
            static std::map<LongInt, SmallType> factor_out_2(LongInt& number_to_factorise);
    };
}
