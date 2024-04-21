#pragma once

#include "defines.h"
#include "math_functions.h"
#include "strong_pseudoprime_test.h"
#include "trial_division.h"

namespace project {
    struct PollardRho {
        public:
            static std::map<LongInt, SmallType> factorize(const LongInt& number);
        private:
            static LongInt factor_one(LongInt& number);
    };
}
