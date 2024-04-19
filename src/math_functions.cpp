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

    LongInt Maths::gcd(LongInt a, LongInt b) {
        while (b != 0) {
            a %= b;
            std::swap(a, b);
        }
        return a;
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

    SmallType Maths::find_legendre(LongInt n, LongInt p) {
        SmallType symbol = 1;
        n %= p;
        if (n == 0) {
            return 0;
        }
        symbol *= factor_out_2(n, p);
        while (n > 1) {
            if ((n - 1) * (p - 1) % 8 == 4) {
                symbol *= -1;
            }
            std::swap(n, p);
            n %= p;
            symbol *= factor_out_2(n, p);
        }
        return symbol;
    }
    LongInt Maths::pow(const LongInt& num, LongInt& deg) {
        if (deg == 0) {
            return 1;
        }
        if (deg % 2 == 1) {
            return Maths::pow(num, --deg) * num;
        }
        deg /= 2;
        LongInt ans = Maths::pow(num, deg);
        return ans * ans;
    }

    }
