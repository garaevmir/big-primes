#include "pollard-rho.h"

paired_vector run_pollard_rho(main_type number) {
    paired_vector factorization;

    while (number != 1) {
        main_type answer = pollard_rho(number);

        main_type deg = 0;
        while (number % answer == 0) {
            number /= answer;
            ++deg;
        }
        factorization.push_back({ answer, deg });
    }
    return factorization;
}

main_type function(main_type number, main_type mod) {
    return (number * number + 1) % mod;
}

main_type pollard_rho(main_type number) {
    main_type x = 2;
    main_type y = x;
    main_type d = 1;
    while (d == 1) {
        x = function(x, number);
        y = function(function(y, number), number);
        d = gcd(abs(x - y), number);
    }
    return d;
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
