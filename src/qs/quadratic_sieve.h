#pragma once

#include "defines.h"
#include "math_functions.h"
#include "strong_pseudoprime_test.h"
#include <boost/random.hpp>
#include <boost/random/random_device.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

namespace BigPrimes {
	struct QuadraticSieve {
            public:
                QuadraticSieve(const LongInt& number) {
                    number_to_factorise = number;
                    guessing_parametres();
                }
                QuadraticSieve(const LongInt& number, const SmallType& factors_limit, const SmallType& border) {
                    number_to_factorise = number;
                    factors_amount = factors_limit;
                    max_num = factors_limit * 100 + 1;
                    sieve_size = border;
                };
                void update_number(const LongInt& number);
                void update_number(const LongInt& number, const SmallType& factors_limit, const SmallType& border);
                std::map<LongInt, SmallType> factorize(const LongInt& number);
                LongInt factor_one(const LongInt& number);
            private:
                LongInt number_to_factorise;
                SmallType factors_amount;
                SmallType max_num;
                SmallType sieve_size;
                void guessing_parametres();
                LongInt find_factor(const std::vector<std::vector<SmallType>>& matrix,
                                                    const std::vector<std::vector<SmallType>>& used,
                                                    const std::vector<SmallType>& factor_base,
                                                    const std::vector<SmallType>& numbers_indexes,
                                                    const std::vector<LongInt>& values_vector);
                void process_candidates(const std::vector<std::vector<SmallType>>& matrix,
                                                        const std::vector<SmallType>& numbers_indexes,
                                                        const std::vector<LongInt>& values_vector,
                                                        std::vector<SmallType>& row, LongInt & x, IndexType& j);
                std::vector<std::vector<SmallType>> factor_suspects(const std::vector<LongInt>& values_vector,
                                                                    const std::vector<SmallType>& factor_base,
                                                                    std::vector<SmallType>& numbers_indexes);
                std::vector<std::vector<SmallType>> gaussian_elimination(const std::vector<std::vector<SmallType>>& matrix);
                std::vector<LongInt> sieving(const std::vector<SmallType>& factor_base);
                std::vector<SmallType> find_factor_base();
	};
}
