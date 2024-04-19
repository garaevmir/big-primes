#include "strong_pseudoprime_test.h"

namespace project {
    bool run_strong_pseudoprime_test(const LongInt& number) {
        SmallType number_length = 0;
        LongInt temp = number;
        while (temp) {
            temp /= 10;
            ++number_length;
        }
        number_length *= number_length;
        temp = 1;
        while (number_length > 0) {
            for (LongInt i = temp + 2; i < number; i += 2) {
                if (number % i != 0) {
                    temp = i;
                    break;
                }
            }
            if (!strong_pseudoprime_test(number, temp)) {
                return false;
            }
            --number_length;
        }
        return true;
    }

    bool strong_pseudoprime_test(const LongInt& number, const LongInt& prime_to_number) {
        LongInt temp = number - 1;
        LongInt two_degree = 0;
        while (temp % 2 == 0) {
            temp /= 2;
            ++two_degree;
        }
        temp = Maths::pow_mod(prime_to_number, temp, number);
        if (temp == 1 || temp == number - 1) {
            return true;
        }
        for (LongInt i = 1; i < two_degree; ++i) {
            temp = (temp * temp) % number;
            if (temp == number - 1) {
                return true;
            }
        }
        return false;
    }
}
