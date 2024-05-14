#pragma once

#include "defines.h"
#include "math_functions.h"


namespace BigPrimes {
    struct PseudoprimeTest {
        public:
            static bool is_prime(const LongInt& number);
        private:
            static LongInt factor_one(const LongInt& number_to_factorise, LongInt& start);
            static bool is_witness(const LongInt& number, const LongInt& prime_to_number);
    };
}
