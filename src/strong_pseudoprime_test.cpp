#include "strong_pseudoprime_test.h"

namespace BigPrimes {
    bool PseudoprimeTest::is_prime(const LongInt& number) {
        // Test works badly with those numbers
        if (number == 1 || number == 2 || number == 3) {
            return true;
        }
        SmallType number_length = 0;
        LongInt temp = number;
        while (temp) {
            temp /= 10;
            ++number_length;
        }
        number_length *= number_length;
        temp = 1;
        while (number_length > 0) {
            temp = factor_one(number, temp);
            if (!is_witness(number, temp)) {
                return false;
            }
            --number_length;
        }
        return true;
    }

    LongInt PseudoprimeTest::factor_one(const LongInt& number_to_factorise, LongInt& start) {
        for (LongInt i = start + 2; i < number_to_factorise; i += 2) {
            if (number_to_factorise % i != 0) {
                return i;
            }
        }
        return number_to_factorise;
    }

    bool PseudoprimeTest::is_witness(const LongInt& number, const LongInt& prime_to_number) {
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
