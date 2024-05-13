#pragma once

#include "defines.h"
#include "math_functions.h"
#include "strong_pseudoprime_test.h"
#include "trial_division.h"
#include <map>

namespace BigPrimes {
    struct PollardRho {
        public:
            static std::map<LongInt, SmallType> factorize(const LongInt& number);
            static LongInt factor_one(const LongInt& number);
        private:
            static const LongInt limit;
    };
}
