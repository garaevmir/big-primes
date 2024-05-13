#include "quadratic_sieve.h"

namespace BigPrimes {
    QuadraticSieve::QuadraticSieve(const BigPrimes::LongInt& number) : number_to_factorise_(number){
        guessing_parametres();
    }

    QuadraticSieve::QuadraticSieve(const BigPrimes::LongInt& number, const BigPrimes::SmallType& factors_limit, const BigPrimes::SmallType& border) : number_to_factorise_(number), factors_amount_(factors_limit), sieve_size_(border) {
        max_num_ = factors_limit * 100 + 1;
    }

    void QuadraticSieve::update_number(const LongInt& number) {
        number_to_factorise_ = number;
        guessing_parametres();
    }

    void QuadraticSieve::update_number(const LongInt& number, const SmallType& factors_limit, const SmallType& border) {
        number_to_factorise_ = number;
        factors_amount_ = factors_limit;
        max_num_ = factors_amount_ * 100 + 1;
        sieve_size_ = border;
    }

    std::map<LongInt, SmallType> QuadraticSieve::factorize(const LongInt& number) {
        std::map<LongInt, SmallType> factorization;
        while (number_to_factorise_ != 1) {
            LongInt factor = factor_one(number);
            SmallType deg = 0;
            while (number_to_factorise_ % factor == 0) {
                number_to_factorise_ /= factor;
                ++deg;
            }
            factorization[factor] += deg;
            if (number_to_factorise_ > 10000 && PseudoprimeTest::is_prime(number_to_factorise_)) {
                factorization[number_to_factorise_] += 1;
                break;
            }
            guessing_parametres();
        }
        return factorization;
    }

    LongInt QuadraticSieve::factor_one(const LongInt& number) const {
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
                                            std::vector<SmallType>& row, LongInt & x, IndexType& j) const {
        x = (values_vector[numbers_indexes[j]] * x);
        for (IndexType l = 0; l < row.size(); ++l) {
            row[l] += matrix[j][l];
        }
    }

    LongInt QuadraticSieve::find_factor(const std::vector<std::vector<SmallType>>& matrix,
                                        const std::vector<std::vector<SmallType>>& used,
                                        const std::vector<SmallType>& factor_base,
                                        const std::vector<SmallType>& numbers_indexes,
                                        const std::vector<LongInt>& values_vector) const {
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
            LongInt temp = Maths::gcd((x - y + number_to_factorise_) % number_to_factorise_, LongInt(number_to_factorise_));
            if (temp != 1 && temp != number_to_factorise_) {
                return temp;
            }
        }
        return number_to_factorise_;
    }

    std::vector<std::vector<SmallType>> QuadraticSieve::factor_suspects(const std::vector<LongInt>& values_vector,
                                                                        const std::vector<SmallType>& factor_base,
                                                                        std::vector<SmallType>& numbers_indexes) const {
        std::vector<std::vector<SmallType>> matrix;
        for (IndexType i = 0; i < values_vector.size(); ++i) {
            std::vector<SmallType> row(factors_amount_, 0);
            LongInt number = values_vector[i] * values_vector[i] - number_to_factorise_;
            for (IndexType j = 0; j < factors_amount_; ++j) {
                SmallType temp = 0;
                while (number % factor_base[j] == 0) {
                    ++temp;
                    number /= factor_base[j];
                }
                row[j] = temp;
                if (number == 1) {
                    matrix.push_back(std::move(row));
                    numbers_indexes.push_back(SmallType(i));
                    break;
                }
            }
        }
        return matrix;
    }

    void QuadraticSieve::reduce_values(const IndexType& start, const SmallType& i, std::vector<LongInt>& sieve) const {
        for (auto l = start; l < 2 * sieve_size_; l += i) {
            while (sieve[l] % i == 0) {
                sieve[l] /= i;
            }
        }
    }

    std::vector<LongInt> QuadraticSieve::sieving(const std::vector<SmallType>& factor_base) const {
        LongInt numbers_root = boost::multiprecision::sqrt(number_to_factorise_) + 1;
        std::vector<LongInt> sieve(2 * sieve_size_);
        for (IndexType i = 0; i < 2 * sieve_size_; ++i) {
            sieve[i] = (numbers_root + i) * (numbers_root + i) - number_to_factorise_;
        }
        for (SmallType i : factor_base) {
            std::vector<LongInt> congruences = Maths::find_congruences(number_to_factorise_, i);
            for (const LongInt& j : congruences) {
                IndexType start = IndexType((j - numbers_root) % i + i) % i;
                reduce_values(start, i, sieve);
            }
        }
        std::vector<LongInt> vec;
        for (IndexType i = 0; i < 2 * sieve_size_; ++i) {
            if (sieve[i] == 1) {
                vec.emplace_back(numbers_root + i);
            }
        }
        return vec;
    }

    std::vector<SmallType> QuadraticSieve::find_factor_base() const {
        std::vector<SmallType> factor_base(factors_amount_);
        factor_base[0] = 2;
        SmallType current_factors = 1;
        std::vector<bool> sieve(max_num_, true);
        for (IndexType i = 3; i < max_num_ && current_factors < factors_amount_; i += 2) {
            if (sieve[i]) {
                if (Maths::find_legendre(number_to_factorise_, i) == 1) {
                    factor_base[current_factors++] = SmallType(i);
                }
                for (IndexType j = 2 * i; j < max_num_; j += i) {
                    sieve[j] = false;
                }
            }
        }
        return factor_base;
    }

    void QuadraticSieve::guessing_parametres() {
        LongInt temp = number_to_factorise_;
        SmallType digits = Maths::number_of_digits(temp);
        if (digits < 16) {
            factors_amount_ = 100;
            max_num_ = factors_amount_ * 100 + 1;
            sieve_size_ = 5000;
            return;
        }
        if (digits < 24) {
            factors_amount_ = 1000;
            max_num_ = factors_amount_ * 100 + 1;
            sieve_size_ = 50000;
            return;
        }
        if (digits < 32) {
            factors_amount_ = 2000;
            max_num_ = factors_amount_ * 100 + 1;
            sieve_size_ = 200000;
            return;
        }
        if (digits < 40) {
            factors_amount_ = 4000;
            max_num_ = factors_amount_ * 100 + 1;
            sieve_size_ = 800000;
            return;
        }
        if (digits < 48) {
            factors_amount_ = 8000;
            max_num_ = factors_amount_ * 100 + 1;
            sieve_size_ = 3200000;
            return;
        }
        if (digits < 56) {
            factors_amount_ = 32000;
            max_num_ = factors_amount_ * 100 + 1;
            sieve_size_ = 51200000;
            return;
        }
    }
}
