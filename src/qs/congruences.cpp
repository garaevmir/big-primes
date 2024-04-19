#include "congruences.h"

namespace project {
    LongInt QuadraticSieve::find_congruence(const LongInt& mod) {
        LongInt s = 0;
        LongInt q = mod - 1;
        while (q % 2 == 0) {
            q /= 2;
            ++s;
        }
        if (s == 1) {
            LongInt temp = (mod + 1) / 4;
            return Maths::pow_mod(number_to_factorise, temp, mod);
        }
        LongInt c = 0;
        for (LongInt i = 2; i < mod; ++i) {
            if (Maths::find_legendre(i, mod) == -1) {
                c = i;
                break;
            }
        }
        c = Maths::pow_mod(c, q, mod);
        LongInt r = (q + 1) / 2;
        r = Maths::pow_mod(number_to_factorise, r, mod);
        LongInt t = Maths::pow_mod(number_to_factorise, q, mod);
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
            LongInt two = 2, power = s - ind - 1;
            LongInt b = Maths::pow_mod(two, power, number_to_factorise);
            b = Maths::pow_mod(c, b, mod);
            r = (r * b) % mod;
            t = (((b * b) % mod) * t) % mod;
            c = (b * b) % mod;
            s = ind;
        }
        return r;
    }

    std::vector<LongInt> QuadraticSieve::find_congruences(const LongInt& p) {
        if (p == 2) {
            return {(number_to_factorise % p)};
        }
        LongInt congruence = find_congruence(p);
        return {congruence, p - congruence};
    }
    }
