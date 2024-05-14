#include "math_functions.h"
#include "trial_division.h"
#include <gtest/gtest.h>

namespace Test {
    TEST(TestTrialDivision, OneFactor) {
        BigPrimes::LongInt number = 705;
        EXPECT_EQ(0, number % BigPrimes::TrialDivision::factor_one(number));
        number = 45023;
        EXPECT_EQ(0, number % BigPrimes::TrialDivision::factor_one(number));
        number = 1097010613;
        EXPECT_EQ(0, number % BigPrimes::TrialDivision::factor_one(number));
        number = 397166490301909;
        EXPECT_EQ(0, number % BigPrimes::TrialDivision::factor_one(number));
        number = BigPrimes::LongInt("10692119085417692189");
        EXPECT_EQ(0, number % BigPrimes::TrialDivision::factor_one(number));
        number = BigPrimes::LongInt("1340739765032470240000933");
        EXPECT_EQ(0, number % BigPrimes::TrialDivision::factor_one(number));
        number = BigPrimes::LongInt("57388947496693346193146341306536502913894044311157");
        EXPECT_EQ(0, number % BigPrimes::TrialDivision::factor_one(number));
    }
    TEST(TestTrialDivision, FactorizeTest) {
        BigPrimes::LongInt number = 705;
        auto factors = BigPrimes::TrialDivision::factorize(number);
        EXPECT_EQ(number, BigPrimes::Maths::multiply_factors(factors));
        number = 45023;
        factors = BigPrimes::TrialDivision::factorize(number);
        EXPECT_EQ(number, BigPrimes::Maths::multiply_factors(factors));
        number = 1097010613;
        factors = BigPrimes::TrialDivision::factorize(number);
        EXPECT_EQ(number, BigPrimes::Maths::multiply_factors(factors));
        number = 397166490301909;
        factors = BigPrimes::TrialDivision::factorize(number);
        EXPECT_EQ(number, BigPrimes::Maths::multiply_factors(factors));
        number = BigPrimes::LongInt("10692119085417692189");
        factors = BigPrimes::TrialDivision::factorize(number);
        EXPECT_EQ(number, BigPrimes::Maths::multiply_factors(factors));
        number = BigPrimes::LongInt("1340739765032470240000933");
        factors = BigPrimes::TrialDivision::factorize(number);
        EXPECT_EQ(number, BigPrimes::Maths::multiply_factors(factors));
        number = BigPrimes::LongInt("57388947496693346193146341306536502913894044311157");
        factors = BigPrimes::TrialDivision::factorize(number);
        EXPECT_EQ(number, BigPrimes::Maths::multiply_factors(factors));
    }
}
