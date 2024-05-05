#include "math_functions.h"

namespace project{
    LongInt Maths::pow_mod(const LongInt& num, LongInt& deg, const LongInt& module) {
        if (deg == 0) {
            return 1;
        }
        if (deg % 2 == 1) {
            return (pow_mod(num, --deg, module) * num) % module;
        }
        deg /= 2;
        LongInt ans = pow_mod(num, deg, module);
        return (ans * ans) % module;
    }

    LongInt Maths::pow(const LongInt& num, LongInt& deg) {
        if (deg == 0) {
            return 1;
        }
        if (deg % 2 == 1) {
            return pow(num, --deg) * num;
        }
        deg /= 2;
        LongInt ans = pow(num, deg);
        return ans * ans;
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

    SmallType Maths::factor_out_2(LongInt& n, LongInt& p) {
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
            auto temp = project::LongInt(i.second);
            number *= project::Maths::pow(i.first, temp);
        }
        return number;
    }

    LongInt Maths::find_congruence(const LongInt& number,const LongInt& mod) {
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
        LongInt qc = q;
        c = pow_mod(c, qc, mod);
        qc = q;
        LongInt t = pow_mod(number, qc, mod);
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
        LongInt congruence = find_congruence(number, p);
        return {congruence, p - congruence};
    }
    }
