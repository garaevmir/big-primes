#include "pollard-rho.h"

namespace project {
    std::map<LongInt, SmallType> PollardRho::factorize(const LongInt &number) {
        std::map<LongInt, SmallType> factorization;
        LongInt number_to_factorise = number;
        while (number_to_factorise != 1) {
            LongInt factor = factor_one(number_to_factorise);
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

    LongInt PollardRho::factor_one(const LongInt &number) {
        LongInt limit = 100000;
        LongInt c = 1;
        LongInt x = 2;
        LongInt y = x * x + c;
        LongInt product = 1;
        LongInt range = 1;
        SmallType i = 0;
        while (i <= limit) {
            for (LongInt j = 0; j < range; ++j) {
                y = (y * y + c) % number;
                product = (product * (x - y) % number + number) % number;
                if (++i % 10 == 0) {
                    LongInt sus = gcd(number, product);
                    if (sus > 1) {
                        return sus;
                    }
                    product = 1;
                }
            }
            x = y;
            range *= 2;
            for (LongInt j = 0; j < range; ++j) {
                y = (y * y + c) % number;
            }
        }
        return number;
    }
}