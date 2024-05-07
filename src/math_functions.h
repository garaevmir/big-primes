#pragma once

#include "defines.h"

namespace BigPrimes {
    struct Maths {
        public:
            static LongInt pow_mod(const LongInt& num, const LongInt& deg, const LongInt& module);
            static LongInt pow(const LongInt& num, const LongInt& deg);
            static LongInt gcd(const LongInt& a, const LongInt& b);
            static SmallType find_legendre(const LongInt& n, const LongInt& p);
            static LongInt multiply_factors(const std::map<LongInt, SmallType>& factors);
            static LongInt find_congruence(const LongInt& number,const LongInt& mod);
            static std::vector<LongInt> find_congruences(const LongInt& number, const LongInt& p);
        private:
            static SmallType factor_out_2(LongInt& n, LongInt& p);
    };
    }
