#pragma once

#include "../defines.h"
#include "congruences.h"
#include "../math_functions.h"
#include <boost/random.hpp>
#include <boost/random/random_device.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include "../print_functions.h"
#include "linear_algebra.h"

namespace project {
	struct QuadraticSieve {
		public:
            QuadraticSieve(const LongInt& number, const SmallType& factors_limit, const SmallType& border) {
                number_to_factorise = number;
                factors_amount = factors_limit;
                max_num = factors_limit * 100 + 1;
                rad = border;
            };
            LongInt find_factor();
        private:
            LongInt number_to_factorise;
            SmallType factors_amount = 100;
            SmallType max_num;
            SmallType rad = 5000;
            LongFloat special = 2.0;
            std::vector<std::vector<SmallType>> factor_suspects(const std::vector<LongInt>& values_vector,
                                                                const std::vector<SmallType> factor_base,
                                                                std::vector<SmallType>& numbers_indexes);
            std::vector<std::vector<SmallType>> gaussian_elimination(std::vector<std::vector<SmallType>>& matrix);
            std::vector<LongInt> sieving(const std::vector<SmallType>& factor_base);
            std::vector<SmallType> find_factor_base();
            std::vector<LongInt> find_congruences(const LongInt& p);
            LongInt find_congruence(const LongInt& mod);
	};
}
