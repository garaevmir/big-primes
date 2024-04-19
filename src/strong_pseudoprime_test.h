#pragma once

#include "defines.h"
#include "math_functions.h"


namespace project {
    bool run_strong_pseudoprime_test(const LongInt& number);

    bool strong_pseudoprime_test(const LongInt& number, const LongInt& prime_to_number);
}
