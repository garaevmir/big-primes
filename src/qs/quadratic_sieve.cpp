#include "quadratic_sieve.h"

namespace project {
    LongInt QuadraticSieve::find_factor() {
        // std::vector<std::vector<LongInt>> a = {{1, 0, 1, 1}, {1, 0, 1, 1}, {0, 0, 1, 1}, {1, 0, 1, 0}, {0, 0, 0, 1}};
        // std::cout << "^^^^^^^^\n";

        auto factor_base = find_factor_base();
        // print_vector(factor_base);
        std::cout << "********\n";
        auto values_vector = sieving(factor_base);
        print_vector(values_vector);
        std::vector<SmallType> numbers_indexes;
        auto matrix = factor_suspects(values_vector, factor_base, numbers_indexes);
        for (auto i : matrix) {
            LongInt num = 1;
            for (IndexType j = 0; j < i.size(); ++j) {
                std::cout << i[j] << ' ';
                if (j == 0) {
                    num *= -1;
                    continue;
                }
                LongInt a = i[j];
                num *= Maths::pow(factor_base[j - 1], a);
            }
            // numbers.push_back(num);
            std::cout << num << '\n';
        }
        std::cout << "---------------\n";
        for (auto i : numbers_indexes) {
            std::cout << values_vector[i] - 2235953 << ' ';
        }
        std::cout << '\n';
        auto used = gaussian_elimination(matrix);
        for (IndexType i = 0; i < used.size(); ++i) {
            LongInt x = 1;
            LongInt y = 1;
            std::vector<SmallType> row(factor_base.size(), 0);
            for (IndexType j = 0; j < used[i].size(); ++j) {
                // std::cout << used[i][j] << ' ';
                if (used[i][j]) {
                    x = (values_vector[numbers_indexes[j]] * x) % number_to_factorise;
                    for (IndexType l = 0; l < row.size(); ++l) {
                        row[l] += matrix[j][l];
                    }
                }
            }
            for (IndexType j = 0; j < row.size(); ++j) {
                LongInt temp = row[j] / 2;
                y = (Maths::pow_mod(factor_base[j], temp, number_to_factorise) * y) % number_to_factorise;
            }
            LongInt temp = Maths::gcd((x > y ? x - y : y - x), LongInt(number_to_factorise));
            std::cout << x << ' ' << y << ' ' << temp << '\n';
            if (temp != 1 && temp != number_to_factorise) {
                std::cout << temp << '\n';
                return temp;
            }
            // std::cout << '\n';
        }
        // std::cout << "===================\n";
        return 0;
    }

    std::vector<std::vector<SmallType>> QuadraticSieve::factor_suspects(const std::vector<LongInt>& values_vector,
                                                                        const std::vector<SmallType> factor_base,
                                                                        std::vector<SmallType>& numbers_indexes) {
        std::cout << "suspects enter\n";
        std::vector<std::vector<SmallType>> matrix;
        for (IndexType i = 0; i < values_vector.size(); ++i) {
            std::vector<SmallType> row(factors_amount, 0);
            LongInt number = values_vector[i] * values_vector[i] - number_to_factorise;
            // std::cout << "==================\n" << values_vector[i] << "\n---------------------\n";
            for (IndexType j = 0; j < factors_amount; ++j) {
                SmallType temp = 0;
                while (number % factor_base[j] == 0) {
                    ++temp;
                    number /= factor_base[j];
                }
                // if (temp) {
                //     std::cout << factor_base[j - 1] << ' ' << temp << '\n';
                // }
                row[j] = temp;
                if (number == 1) {
                    std::reverse(row.begin(), row.end());
                    matrix.push_back(row);
                    numbers_indexes.push_back(i);
                    break;
                }
            }
        }
        std::cout << "suspects exit\n";
        return matrix;
    }

    std::vector<LongInt> QuadraticSieve::sieving(const std::vector<SmallType>& factor_base) {
        std::cout << "sieving enter\n";
        LongInt numbers_root = boost::multiprecision::sqrt(number_to_factorise) + 1;
        std::vector<LongFloat> sieve(2 * rad);
        for (SmallType i : factor_base) {
            std::vector<LongInt> congruences = find_congruences(i);
            for (LongInt j : congruences) {
                LongInt start = (numbers_root / i) * i + j;
                if (start < numbers_root) {
                    start += i;
                }
                start -= numbers_root;
                // IndexType start = IndexType((j - (numbers_root - rad) % i) + i);
                for (IndexType l = IndexType(start); l < 2 * rad; l += IndexType(i)) {
                    sieve[l] += log(LongFloat(i));
                }
            }
        }
        LongFloat num_log = log(LongFloat(number_to_factorise));
        LongFloat closenuf = (num_log / 2) + log(2 * rad) - special * log(factor_base.back());
        std::vector<LongInt> vec;
        for (IndexType i = 0; i < 2 * rad; ++i) {
            if (sieve[i] >= closenuf) {
                vec.push_back(numbers_root + i);
                // std::cout << i << '\n';
            }
        }
        std::cout << "sieving exit\n";
        return vec;
    }

    std::vector<SmallType> QuadraticSieve::find_factor_base() {
        std::cout << "factor base enter\n";
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
        std::cout << "factor base exit\n";
        return factor_base;
    }

};  // namespace project
