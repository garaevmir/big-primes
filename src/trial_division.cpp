#include "trial_division.h"

namespace project {
    LongInt TrialDivision::border_for_divisor(const LongInt& number) {
        return sqrt(number) + 1;
    }

    //bool TrialDivision::is_prime() {
    //    if (number_to_factorize % 2 == 0 && number_to_factorize != 2) {
    //        return false;
    //    }
    //    for (LongInt i = 3; i < border_for_divisor(number_to_factorize); i += 2) {
    //        if (number_to_factorize % i == 0) {
    //            return false;
    //        }
    // 
    //    }
    //    return true;
    //}

    LongInt TrialDivision::factor_one(LongInt& start) {
        for (LongInt i = start + 2; i < border_for_divisor(number_to_factorize); i += 2) {
            if (number_to_factorize % i == 0) {
                return i;
            }
        }
        return number_to_factorize;
    }

    SmallType TrialDivision::find_degree(const LongInt& factor) {
        SmallType deg = 0;
        while (number_to_factorize % factor == 0) {
            number_to_factorize /= factor;
            ++deg;
        }
        return deg;
    }

    void TrialDivision::factor_out_2() {
        if (number_to_factorize % 2 == 0) {
            LongInt temp = 2;
            factors.push_back({2, find_degree(temp)});
        }
    }

    std::vector<factorization> TrialDivision::factorize() {
        LongInt last = 1;
        factor_out_2();
        while (number_to_factorize != 1) {
            last = factor_one(last);
            factors.push_back({last, find_degree(last)});
        }
        return factors;
    }
}
