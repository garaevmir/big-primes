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
        }
        return factorization;
    }
    LongInt PollardRho::factor_one(LongInt &number) {
        LongInt limit = 10000;
        LongInt c = 1;
        LongInt temp_1 = 2;
        LongInt temp_2 = 4 + c;
        LongInt product = 1;
        LongInt range = 1;
        SmallType i = 0;
        while (i <= limit) {
            for (LongInt j = 0; j < range; ++j) {
                temp_2 = (temp_2 * temp_2 + c) % number;
                product = (product * (temp_1 - temp_2) % number + number) % number;

                ++i;
                if (i % 10 == 0) {
                    LongInt sus = gcd(number, product);
                    if (sus > 1) {
                        return sus;
                    }
                    product = 1;
                }
            }
            temp_1 = temp_2;
            range *= 2;
            for (LongInt j = 0; j < range; ++j) {
                temp_2 = (temp_2 * temp_2 + c) % number;
            }
        }
        return number;
    }

};
