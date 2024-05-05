#pragma once

#include "defines.h"
#include "strong_pseudoprime_test.h"

namespace BigPrimes {
    struct TrialDivision {
        public:
            static std::map<LongInt, SmallType> factorize(const LongInt& number);
            static LongInt factor_one(const LongInt& number_to_factorise);
        private:
            static LongInt factor_one_bound(const LongInt& number_to_factorise, const LongInt& start);
            static LongInt border_for_divisor(const LongInt& number);
            static LongInt lower_bound(const LongInt& start);
            static SmallType find_degree(LongInt& number_to_factorise, const LongInt& factor);
            static std::map<LongInt, SmallType> factor_out_2(LongInt& number_to_factorise);
    };
}
