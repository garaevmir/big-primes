#include "trial_division.h"

namespace project {
    LongInt TrialDivision::border_for_divisor(const LongInt& number) {
        return sqrt(number) + 1;
    }

    LongInt TrialDivision::factor_one(const LongInt& number_to_factorise, LongInt& start) {
        for (LongInt i = start + 2; i < border_for_divisor(number_to_factorise); i += 2) {
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

    std::vector<factorization> TrialDivision::factor_out_2(LongInt& number_to_factorise) {
        std::vector<factorization> factors;
        if (number_to_factorise % 2 == 0) {
            LongInt temp = 2;
            factors.push_back({2, find_degree(number_to_factorise, temp)});
        }
        return factors;
    }

    std::vector<factorization> TrialDivision::factorize(const LongInt& number) {
        LongInt number_to_factorise = number;
        std::vector<factorization> factors = factor_out_2(number_to_factorise);
        LongInt last = 1;
        while (number_to_factorise != 1) {
            last = factor_one(number_to_factorise, last);
            factors.push_back({last, find_degree(number_to_factorise, last)});
        }
        return factors;
    }
}
