#include "pollard-rho.h"

namespace project {
    std::vector<factorization> run_pollard_rho(LongInt number) {
        std::vector<factorization> factorization;

        while (number != 1) {
            LongInt answer = pollard_rho(number);

            SmallType deg = 0;
            while (number % answer == 0) {
                number /= answer;
                ++deg;
            }
            factorization.push_back({answer, deg});
        }
        return factorization;
    }

    LongInt function(LongInt number, LongInt mod) {
        return (number * number + 1) % mod;
    }

    LongInt pollard_rho(LongInt number) {
        LongInt x = 2;
        LongInt y = x;
        LongInt d = 1;
        while (d == 1) {
            x = function(x, number);
            y = function(function(y, number), number);
            d = gcd(abs(x - y), number);
        }
        return d;
    }
}

//main_type new_pollard_rho(main_type number, small_type c, small_type limit) {
//    main_type temp_1 = 2;
//    main_type temp_2 = 4 + c;
//    main_type product = 1;
//    main_type range = 1;
//    small_type i = 0;
//    while (i <= limit) {
//        for (main_type j = 0; j < range; ++j) {
//            temp_2 = (temp_2 * temp_2 + c) % number;
//            product = product * (temp_1 - temp_2) % number;
//            if (product < 0) {
//                product += number;
//            }
//            ++i;
//            if (i % 100 == 0) {
//                main_type sus = gcd(number, product);
//                if (sus > 1) {
//                    return sus;
//                }
//                product = 1;
//            }
//        }
//        temp_1 = temp_2;
//        range *= 2;
//        for (main_type j = 0; j < range; ++j) {
//            temp_2 = (temp_2 * temp_2 + c) % number;
//        }
//    }
//    return number;
//}
