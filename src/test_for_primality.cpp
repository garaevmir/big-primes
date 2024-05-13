#include "test_for_primality.h"

namespace BigPrimes {
    bool LucasPrimalityTest::is_prime(const LongInt& number_to_test) {
        LongInt temp = number_to_test - 1;
        std::map<LongInt, SmallType> factorization = TrialDivision::factorize(temp);
        LongInt border = min(number_to_test, computing_border(number_to_test));
        LongInt i = 2;
        if (testing(number_to_test, i, factorization)) {
            return true;
        }
        for (i = 3; i < border; i += 2) {
            if (testing(number_to_test, i, factorization)) {
                return true;
            }
        }
        return false;
    }

    LongInt LucasPrimalityTest::computing_border(const LongInt& number_to_test) {
        LongInt border = LongInt(log(LongFloat(number_to_test))) + 1;
        return border * border * border;
    }
    bool LucasPrimalityTest::run_factors(const LongInt& number_to_test, LongInt& temp, const LongInt& arg,
                                         const std::map<LongInt, SmallType>& factors) {
        for (const auto& j : factors) {
            temp = (number_to_test - 1) / j.first;
            if (Maths::pow_mod(arg, temp, number_to_test) == 1) {
                return false;
            }
        }
        return true;
    }

    bool LucasPrimalityTest::testing(const LongInt& number_to_test, const LongInt& arg,
                                     const std::map<LongInt, SmallType>& factors) {
        LongInt temp = number_to_test - 1;
        if (Maths::pow_mod(arg, temp, number_to_test) == 1) {
            return run_factors(number_to_test, temp, arg, factors);
        }
        return false;
    }
}
