#pragma once

#include "defines.h"

namespace project {
    struct Maths {
        public:
            Maths() = default;
            static LongInt pow_mod(const LongInt& num, LongInt& deg, const LongInt& module);
            static LongInt gcd(LongInt a, LongInt b);
            static SmallType find_legendre(LongInt n, LongInt p);
            static LongInt pow(const LongInt& num, LongInt& deg);
        private:
            static SmallType factor_out_2(LongInt& n, LongInt& p);
    };
    }
