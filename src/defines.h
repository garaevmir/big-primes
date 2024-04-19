#pragma once

#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

namespace project {
    using LongInt = boost::multiprecision::cpp_int;
    using LongFloat = boost::multiprecision::cpp_dec_float_100;
    using SmallType = int;
    using IndexType = size_t;
    struct factorization {
        public:
            LongInt divisor;
            SmallType degree;
    };
}
