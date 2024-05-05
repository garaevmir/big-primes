#include "math_functions.h"
#include "quadratic_sieve.h"
#include <gtest/gtest.h>

namespace Test {
    TEST(TestQuadraticSieve, OneFactor) {
        BigPrimes::LongInt number = 705;
        BigPrimes::QuadraticSieve temp(number);
        EXPECT_EQ(0, number % temp.factor_one(number));
        number = 45023;
        temp.update_number(number);
        EXPECT_EQ(0, number % temp.factor_one(number));
        number = 1097010613;
        temp.update_number(number);
        EXPECT_EQ(0, number % temp.factor_one(number));
        number = 397166490301909;
        temp.update_number(number);
        EXPECT_EQ(0, number % temp.factor_one(number));
        number = BigPrimes::LongInt("10692119085417692189");
        temp.update_number(number);
        EXPECT_EQ(0, number % temp.factor_one(number));
        number = BigPrimes::LongInt("1340739765032470240000933");
        temp.update_number(number);
        EXPECT_EQ(0, number % temp.factor_one(number));
        number = BigPrimes::LongInt("44740747869931444455739288444731585052051587564941");
        temp.update_number(number);
        EXPECT_EQ(0, number % temp.factor_one(number));
    }

    TEST(TestQuadraticSIeve, FactorizeTest) {
        BigPrimes::LongInt number = 705;
        BigPrimes::QuadraticSieve temp(number);
        EXPECT_EQ(number, BigPrimes::Maths::multiply_factors(temp.factorize(number)));
        number = 45023;
        temp.update_number(number);
        EXPECT_EQ(number, BigPrimes::Maths::multiply_factors(temp.factorize(number)));
        number = 1097010613;
        temp.update_number(number);
        EXPECT_EQ(number, BigPrimes::Maths::multiply_factors(temp.factorize(number)));
        number = 397166490301909;
        temp.update_number(number);
        EXPECT_EQ(number, BigPrimes::Maths::multiply_factors(temp.factorize(number)));
        number = BigPrimes::LongInt("10692119085417692189");
        temp.update_number(number);
        EXPECT_EQ(number, BigPrimes::Maths::multiply_factors(temp.factorize(number)));
        number = BigPrimes::LongInt("1340739765032470240000933");
        temp.update_number(number);
        EXPECT_EQ(number, BigPrimes::Maths::multiply_factors(temp.factorize(number)));
        number = BigPrimes::LongInt("44740747869931444455739288444731585052051587564941");
        temp.update_number(number);
        EXPECT_EQ(number, BigPrimes::Maths::multiply_factors(temp.factorize(number)));
    }
}
