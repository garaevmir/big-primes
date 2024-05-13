#pragma once

#include "defines.h"
#include "math_functions.h"
#include "strong_pseudoprime_test.h"
#include <map>

namespace BigPrimes {
	struct QuadraticSieve {
            public:
                QuadraticSieve(const LongInt& number);
                QuadraticSieve(const LongInt& number, const SmallType& factors_limit, const SmallType& border);
                void update_number(const LongInt& number);
                void update_number(const LongInt& number, const SmallType& factors_limit, const SmallType& border);
                std::map<LongInt, SmallType> factorize(const LongInt& number);
                LongInt factor_one(const LongInt& number) const;
            private:
                void process_candidates(const std::vector<std::vector<SmallType>>& matrix,
                                        const std::vector<SmallType>& numbers_indexes,
                                        const std::vector<LongInt>& values_vector,
                                        std::vector<SmallType>& row, LongInt & x, IndexType& j) const;
                LongInt find_factor(const std::vector<std::vector<SmallType>>& matrix,
                                                    const std::vector<std::vector<SmallType>>& used,
                                                    const std::vector<SmallType>& factor_base,
                                                    const std::vector<SmallType>& numbers_indexes,
                                                    const std::vector<LongInt>& values_vector) const;
                std::vector<std::vector<SmallType>> factor_suspects(const std::vector<LongInt>& values_vector,
                                                                    const std::vector<SmallType>& factor_base,
                                                                    std::vector<SmallType>& numbers_indexes) const;
                void reduce_values(const IndexType& start, const SmallType& i, std::vector<LongInt>& sieve) const;
                std::vector<LongInt> sieving(const std::vector<SmallType>& factor_base) const;
                std::vector<SmallType> find_factor_base() const;
                std::vector<std::vector<SmallType>> make_mod_2(std::vector<std::vector<SmallType>> matrix, const LongInt& n, const LongInt& m) const;
                std::vector<std::vector<SmallType>> gaussian_elimination(const std::vector<std::vector<SmallType>>& matrix) const;
                void guessing_parametres();
                LongInt number_to_factorise_;
                SmallType factors_amount_ = 0;
                SmallType max_num_ = 0;
                SmallType sieve_size_ = 0;
	};
}
