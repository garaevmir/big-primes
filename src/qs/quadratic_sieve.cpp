#include "quadratic_sieve.h"

namespace BigPrimes {
    void QuadraticSieve::guessing_parametres() {
        SmallType digits = 0;
        LongInt temp = number_to_factorise;
        while (temp > 0) {
            ++digits;
            temp /= 10;
        }
        if (digits < 16) {
            factors_amount = 100;
            max_num = factors_amount * 100 + 1;
            sieve_size = 5000;
            return;
        }
        if (digits < 24) {
            factors_amount = 1000;
            max_num = factors_amount * 100 + 1;
            sieve_size = 50000;
            return;
        }
        if (digits < 32) {
            factors_amount = 2000;
            max_num = factors_amount * 100 + 1;
            sieve_size = 200000;
            return;
        }
        if (digits < 40) {
            factors_amount = 4000;
            max_num = factors_amount * 100 + 1;
            sieve_size = 800000;
            return;
        }
        if (digits < 48) {
            factors_amount = 8000;
            max_num = factors_amount * 100 + 1;
            sieve_size = 3200000;
            return;
        }
        if (digits < 56) {
            factors_amount = 32000;
            max_num = factors_amount * 100 + 1;
            sieve_size = 51200000;
            return;
        }
    }
    void QuadraticSieve::update_number(const LongInt& number) {
        number_to_factorise = number;
        guessing_parametres();
    }
    void QuadraticSieve::update_number(const LongInt& number, const SmallType& factors_limit, const SmallType& border) {
        number_to_factorise = number;
        factors_amount = factors_limit;
        max_num = factors_amount * 100 + 1;
        sieve_size = border;
    }
    std::map<LongInt, SmallType> QuadraticSieve::factorize(const LongInt& number) {
        std::map<LongInt, SmallType> factorization;
        while (number_to_factorise != 1) {
            LongInt factor = factor_one(number);
            SmallType deg = 0;
            while (number_to_factorise % factor == 0) {
                number_to_factorise /= factor;
                ++deg;
            }
            factorization[factor] += deg;
            if (number_to_factorise > 10000 && PseudoprimeTest::is_prime(number_to_factorise)) {
                factorization[number_to_factorise] += 1;
                break;
            }
        }
        return factorization;
    }
    LongInt QuadraticSieve::factor_one(const LongInt& number) {
        auto factor_base = find_factor_base();
        auto values_vector = sieving(factor_base);
        std::vector<SmallType> numbers_indexes;
        auto matrix = factor_suspects(values_vector, factor_base, numbers_indexes);
        auto used = gaussian_elimination(matrix);
        LongInt factor = find_factor(matrix, used, factor_base, numbers_indexes, values_vector);
        return factor;
    }
    void QuadraticSieve::process_candidates(const std::vector<std::vector<SmallType>>& matrix,
                                            const std::vector<SmallType>& numbers_indexes,
                                            const std::vector<LongInt>& values_vector,
                                            std::vector<SmallType>& row, LongInt & x, IndexType& j) {
        x = (values_vector[numbers_indexes[j]] * x);
        for (IndexType l = 0; l < row.size(); ++l) {
            row[l] += matrix[j][l];
        }
    }
    LongInt QuadraticSieve::find_factor(const std::vector<std::vector<SmallType>>& matrix,
                                        const std::vector<std::vector<SmallType>>& used,
                                        const std::vector<SmallType>& factor_base,
                                        const std::vector<SmallType>& numbers_indexes,
                                        const std::vector<LongInt>& values_vector) {
        for (auto i : used) {
            LongInt x = 1;
            LongInt y = 1;
            std::vector<SmallType> row(factor_base.size(), 0);
            for (IndexType j = 0; j < i.size(); ++j) {
                if (i[j]) {
                    process_candidates(matrix, numbers_indexes, values_vector, row, x, j);
                }
            }
            for (IndexType j = 0; j < row.size(); ++j) {
                LongInt temp = row[j] / 2;
                y = (Maths::pow(factor_base[j], temp) * y);
            }
            LongInt temp = Maths::gcd((x - y + number_to_factorise) % number_to_factorise, LongInt(number_to_factorise));
            if (temp != 1 && temp != number_to_factorise) {
                return temp;
            }
        }
        return number_to_factorise;
    }
    std::vector<std::vector<SmallType>> QuadraticSieve::factor_suspects(const std::vector<LongInt>& values_vector,
                                                                        const std::vector<SmallType>& factor_base,
                                                                        std::vector<SmallType>& numbers_indexes) {
        std::vector<std::vector<SmallType>> matrix;
        for (IndexType i = 0; i < values_vector.size(); ++i) {
            std::vector<SmallType> row(factors_amount, 0);
            LongInt number = values_vector[i] * values_vector[i] - number_to_factorise;
            for (IndexType j = 0; j < factors_amount; ++j) {
                SmallType temp = 0;
                while (number % factor_base[j] == 0) {
                    ++temp;
                    number /= factor_base[j];
                }
                row[j] = temp;
                if (number == 1) {
                    matrix.push_back(row);
                    numbers_indexes.push_back(SmallType(i));
                    break;
                }
            }
        }
        return matrix;
    }
    std::vector<LongInt> QuadraticSieve::sieving(const std::vector<SmallType>& factor_base) {
        LongInt numbers_root = boost::multiprecision::sqrt(number_to_factorise) + 1;
        std::vector<LongInt> sieve(2 * sieve_size);
        for (IndexType i = 0; i < 2 * sieve_size; ++i) {
            sieve[i] = (numbers_root + i) * (numbers_root + i) - number_to_factorise;
        }
        for (SmallType i : factor_base) {
            std::vector<LongInt> congruences = Maths::find_congruences(number_to_factorise, i);
            for (const LongInt& j : congruences) {
                IndexType start = IndexType((j - numbers_root) % i + i) % i;
                for (auto l = IndexType(start); l < 2 * sieve_size; l += IndexType(i)) {
                    while (sieve[l] % i == 0) {
                        sieve[l] /= i;
                    }
                }
            }
        }
        std::vector<LongInt> vec;
        for (IndexType i = 0; i < 2 * sieve_size; ++i) {
            if (sieve[i] == 1) {
                vec.emplace_back(numbers_root + i);
            }
        }
        return vec;
    }
    std::vector<SmallType> QuadraticSieve::find_factor_base() {
        std::vector<SmallType> factor_base(factors_amount);
        factor_base[0] = 2;
        SmallType current_factors = 1;
        std::vector<bool> sieve(max_num, true);
        for (IndexType i = 3; i < max_num && current_factors < factors_amount; i += 2) {
            if (sieve[i]) {
                if (Maths::find_legendre(number_to_factorise, i) == 1) {
                    factor_base[current_factors++] = SmallType(i);
                }
                for (IndexType j = 2 * i; j < max_num; j += i) {
                    sieve[j] = false;
                }
            }
        }
        return factor_base;
    }
}
