#pragma once

#include "defines.h"
#include "math_functions.h"

namespace project {
    std::vector<factorization> run_pollard_rho(LongInt number);
    LongInt function(LongInt number, LongInt mod);
    LongInt pollard_rho(LongInt number);
}

//main_type new_pollard_rho(main_type number, small_type c, small_type limit);
