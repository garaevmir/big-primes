#include "math_functions.h"
#include "trial_division.h"
#include <gtest/gtest.h>

namespace Test {
    TEST(TestTrialDivision, OneFactor) {
        project::LongInt number = 705;
        EXPECT_EQ(0, number % project::TrialDivision::factor_one(number));
        number = 45023;
        EXPECT_EQ(0, number % project::TrialDivision::factor_one(number));
        number = 1097010613;
        EXPECT_EQ(0, number % project::TrialDivision::factor_one(number));
        number = 397166490301909;
        EXPECT_EQ(0, number % project::TrialDivision::factor_one(number));
        number = project::LongInt("10692119085417692189");
        EXPECT_EQ(0, number % project::TrialDivision::factor_one(number));
        number = project::LongInt("1340739765032470240000933");
        EXPECT_EQ(0, number % project::TrialDivision::factor_one(number));
        number = project::LongInt("57388947496693346193146341306536502913894044311157");
        EXPECT_EQ(0, number % project::TrialDivision::factor_one(number));
    }

    TEST(TestTrialDivision, FactorizeTest) {
        project::LongInt number = 705;
        auto factors = project::TrialDivision::factorize(number);
        EXPECT_EQ(number, project::Maths::multiply_factors(factors));
        number = 45023;
        factors = project::TrialDivision::factorize(number);
        EXPECT_EQ(number, project::Maths::multiply_factors(factors));
        number = 1097010613;
        factors = project::TrialDivision::factorize(number);
        EXPECT_EQ(number, project::Maths::multiply_factors(factors));
        number = 397166490301909;
        factors = project::TrialDivision::factorize(number);
        EXPECT_EQ(number, project::Maths::multiply_factors(factors));
        number = project::LongInt("10692119085417692189");
        factors = project::TrialDivision::factorize(number);
        EXPECT_EQ(number, project::Maths::multiply_factors(factors));
        number = project::LongInt("1340739765032470240000933");
        factors = project::TrialDivision::factorize(number);
        EXPECT_EQ(number, project::Maths::multiply_factors(factors));
        number = project::LongInt("57388947496693346193146341306536502913894044311157");
        factors = project::TrialDivision::factorize(number);
        EXPECT_EQ(number, project::Maths::multiply_factors(factors));
    }
}