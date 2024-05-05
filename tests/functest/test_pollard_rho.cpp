#include "math_functions.h"
#include "pollard-rho.h"
#include <gtest/gtest.h>

namespace Test {
    TEST(TestPollardRho, OneFactor) {
        BigPrimes::LongInt number = 705;
        EXPECT_EQ(0, number % BigPrimes::PollardRho::factor_one(number));
        number = 45023;
        EXPECT_EQ(0, number % BigPrimes::PollardRho::factor_one(number));
        number = 1097010613;
        EXPECT_EQ(0, number % BigPrimes::PollardRho::factor_one(number));
        number = 397166490301909;
        EXPECT_EQ(0, number % BigPrimes::PollardRho::factor_one(number));
        number = BigPrimes::LongInt("10692119085417692189");
        EXPECT_EQ(0, number % BigPrimes::PollardRho::factor_one(number));
        number = BigPrimes::LongInt("1340739765032470240000933");
        EXPECT_EQ(0, number % BigPrimes::PollardRho::factor_one(number));
        number = BigPrimes::LongInt("57388947496693346193146341306536502913894044311157");
        EXPECT_EQ(0, number % BigPrimes::PollardRho::factor_one(number));
        number = BigPrimes::LongInt("4587592344173103261443900376261941495420442936345693512940254899327042718929338589101567099577384933");
        EXPECT_EQ(0, number % BigPrimes::PollardRho::factor_one(number));
    }

    TEST(TestPollardRho, FactorizeTest) {
        BigPrimes::LongInt number = 705;
        auto factors = BigPrimes::PollardRho::factorize(number);
        EXPECT_EQ(number, BigPrimes::Maths::multiply_factors(factors));
        number = 45023;
        factors = BigPrimes::PollardRho::factorize(number);
        EXPECT_EQ(number, BigPrimes::Maths::multiply_factors(factors));
        number = 1097010613;
        factors = BigPrimes::PollardRho::factorize(number);
        EXPECT_EQ(number, BigPrimes::Maths::multiply_factors(factors));
        number = 397166490301909;
        factors = BigPrimes::PollardRho::factorize(number);
        EXPECT_EQ(number, BigPrimes::Maths::multiply_factors(factors));
        number = BigPrimes::LongInt("10692119085417692189");
        factors = BigPrimes::PollardRho::factorize(number);
        EXPECT_EQ(number, BigPrimes::Maths::multiply_factors(factors));
        number = BigPrimes::LongInt("1340739765032470240000933");
        factors = BigPrimes::PollardRho::factorize(number);
        EXPECT_EQ(number, BigPrimes::Maths::multiply_factors(factors));
        number = BigPrimes::LongInt("57388947496693346193146341306536502913894044311157");
        factors = BigPrimes::PollardRho::factorize(number);
        EXPECT_EQ(number, BigPrimes::Maths::multiply_factors(factors));
        number = BigPrimes::LongInt("4587592344173103261443900376261941495420442936345693512940254899327042718929338589101567099577384933");
        factors = BigPrimes::PollardRho::factorize(number);
        EXPECT_EQ(number, BigPrimes::Maths::multiply_factors(factors));
    }
}
