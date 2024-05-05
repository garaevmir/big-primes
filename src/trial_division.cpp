#include "trial_division.h"

namespace BigPrimes {
    LongInt TrialDivision::border_for_divisor(const LongInt& number) {
        return sqrt(number) + 1;
    }

    LongInt TrialDivision::lower_bound(const LongInt& start) {
        return  start + 1 + start % 2;
    }

    LongInt TrialDivision::factor_one(const LongInt& number_to_factorise) {
        if (number_to_factorise % 2 == 0) {
            return 2;
        }
        for (LongInt i = 3; i < border_for_divisor(number_to_factorise); i += 2) {
            if (number_to_factorise % i == 0) {
                return i;
            }
        }
        return number_to_factorise;
    }

    LongInt TrialDivision::factor_one_bound(const LongInt& number_to_factorise, const LongInt& start) {
        for (LongInt i = lower_bound(start); i < border_for_divisor(number_to_factorise); i += 2) {
            if (number_to_factorise % i == 0) {
                return i;
            }
        }
        return number_to_factorise;
    }

    SmallType TrialDivision::find_degree(LongInt& number_to_factorise, const LongInt& factor) {
        SmallType deg = 0;
        while (number_to_factorise % factor == 0) {
            number_to_factorise /= factor;
            ++deg;
        }
        return deg;
    }

    std::map<LongInt, SmallType> TrialDivision::factor_out_2(LongInt& number_to_factorise) {
        std::map<LongInt, SmallType> factors;
        if (number_to_factorise % 2 == 0) {
            LongInt temp = 2;
            factors[2] += find_degree(number_to_factorise, temp);
        }
        return factors;
    }

    std::map<LongInt, SmallType> TrialDivision::factorize(const LongInt& number) {
        LongInt number_to_factorise = number;
        std::map<LongInt, SmallType> factors = factor_out_2(number_to_factorise);
        LongInt last = 1;
        while (number_to_factorise != 1) {
            last = factor_one_bound(number_to_factorise, last);
            factors[last] += find_degree(number_to_factorise, last);
            if (number_to_factorise > 10000 && PseudoprimeTest::is_prime(number_to_factorise)) {
                factors[number_to_factorise] += 1;
                break;
            }
        }
        return factors;
    }
}
