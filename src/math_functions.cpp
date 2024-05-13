#include "math_functions.h"

namespace BigPrimes{
    LongInt Maths::pow_mod(const LongInt& num, const LongInt& deg, const LongInt& module) {
        LongInt number_in_degree = 1;
        LongInt normaliser = num;
        LongInt cur_deg = deg;
        while (cur_deg != 0) {
            if ((cur_deg & 1) != 0) {
                number_in_degree = (number_in_degree * normaliser) % module;
            }
            normaliser = (normaliser * normaliser) % module;
            cur_deg >>= 1;
        }
        return number_in_degree;
    }

    LongInt Maths::pow(const LongInt& num, const LongInt& deg) {
        LongInt number_in_degree = 1;
        LongInt normaliser = num;
        LongInt cur_deg = deg;
        while (cur_deg != 0) {
            if ((cur_deg & 1) != 0) {
                number_in_degree *= normaliser;
            }
            normaliser *= normaliser;
            cur_deg >>= 1;
        }
        return number_in_degree;
    }

    LongInt Maths::gcd(const LongInt& a, const LongInt& b) {
        LongInt a_copy = a;
        LongInt b_copy = b;
        while (b_copy != 0) {
            a_copy %= b_copy;
            std::swap(a_copy, b_copy);
        }
        return a_copy;
    }

    SmallType Maths::find_legendre(const LongInt& n, const LongInt& p) {
        LongInt n_copy = n;
        LongInt p_copy = p;
        SmallType symbol = 1;
        n_copy %= p_copy;
        if (n_copy == 0) {
            return 0;
        }
        symbol *= factor_out_2(n_copy, p_copy);
        while (n_copy > 1) {
            if ((n_copy - 1) * (p_copy - 1) % 8 == 4) {
                symbol *= -1;
            }
            std::swap(n_copy, p_copy);
            n_copy %= p_copy;
            symbol *= factor_out_2(n_copy, p_copy);
        }
        return symbol;
    }

    LongInt Maths::multiply_factors(const std::map<LongInt, SmallType>& factors) {
        LongInt number = 1;
        for (const auto& i : factors) {
            auto temp = LongInt(i.second);
            number *= Maths::pow(i.first, temp);
        }
        return number;
    }

    LongInt Maths::find_one_congruence(const LongInt& number, const LongInt& mod) {
        LongInt s = 0;
        LongInt q = mod - 1;
        while (q % 2 == 0) {
            q /= 2;
            ++s;
        }
        if (s == 1) {
            LongInt temp = (mod + 1) / 4;
            return pow_mod(number, temp, mod);
        }
        LongInt c = 0;
        for (LongInt i = 2; i < mod; ++i) {
            if (find_legendre(i, mod) == -1) {
                c = i;
                break;
            }
        }
        c = pow_mod(c, q, mod);
        LongInt t = pow_mod(number, q, mod);
        LongInt r = (q + 1) / 2;
        r = pow_mod(number, r, mod);
        while (t % mod != 1) {
            LongInt ind = 1;
            LongInt temp = t;
            for (LongInt i = 1; i < s; ++i) {
                temp = (temp * temp) % mod;
                if (temp == 1) {
                    ind = i;
                    break;
                }
            }
            LongInt two = 2, power = s - ind - 1, inf = LongInt(1e100);
            LongInt b = pow_mod(two, power, inf);
            b = pow_mod(c, b, mod);
            s = ind;
            r = (r * b) % mod;
            t = (((b * b) % mod) * t) % mod;
            c = (b * b) % mod;
        }
        return r;
    }

    std::vector<LongInt> Maths::find_congruences(const LongInt& number, const LongInt& p) {
        if (p == 2) {
            return {(number % p)};
        }
        LongInt congruence = find_one_congruence(number, p);
        return {congruence, p - congruence};
    }

    SmallType Maths::factor_out_2(LongInt& n, const LongInt& p) {
        int64_t temp = 0;
        while (n % 2 == 0) {
            n /= 2;
            temp = 1 - temp;
        }
        if (temp * (p * p - 1) % 16 == 8) {
            return -1;
        }
        return 1;
    }

    SmallType Maths::number_of_digits(LongInt number) {
        SmallType digits = 0;
        while (number > 0) {
            ++digits;
            number /= 10;
        }
        return digits;
    }
    }
