#include "strong_pseudoprime_test.h"
#include <gtest/gtest.h>

namespace Test {
    TEST(StrongPseudoprimeTest, Primes) {
        EXPECT_EQ(true, BigPrimes::PseudoprimeTest::is_prime(179));
        EXPECT_EQ(true, BigPrimes::PseudoprimeTest::is_prime(41077));
        EXPECT_EQ(true, BigPrimes::PseudoprimeTest::is_prime(5941613819));
        EXPECT_EQ(true, BigPrimes::PseudoprimeTest::is_prime(313372252932373));
        EXPECT_EQ(true, BigPrimes::PseudoprimeTest::is_prime(BigPrimes::LongInt("48452878594687224547")));
        EXPECT_EQ(true, BigPrimes::PseudoprimeTest::is_prime(BigPrimes::LongInt("9815155030774794504603661")));
        EXPECT_EQ(true, BigPrimes::PseudoprimeTest::is_prime(BigPrimes::LongInt("27365084842452949020535457712834761")));
        EXPECT_EQ(true, BigPrimes::PseudoprimeTest::is_prime(BigPrimes::LongInt("74997382925113036024802760153259410990097509328129")));
        EXPECT_EQ(true, BigPrimes::PseudoprimeTest::is_prime(BigPrimes::LongInt("4299627456236271695097163499498705248885485007206706020942071089424297329292721947966917855975996661")));
    }
    TEST(StrongPseudoprimeTest, Composites) {
        EXPECT_EQ(false, BigPrimes::PseudoprimeTest::is_prime(342));
        EXPECT_EQ(false, BigPrimes::PseudoprimeTest::is_prime(90751));
        EXPECT_EQ(false, BigPrimes::PseudoprimeTest::is_prime(4339963843));
        EXPECT_EQ(false, BigPrimes::PseudoprimeTest::is_prime(93931233200855));
        EXPECT_EQ(false, BigPrimes::PseudoprimeTest::is_prime(BigPrimes::LongInt("75583811853085190253")));
        EXPECT_EQ(false, BigPrimes::PseudoprimeTest::is_prime(BigPrimes::LongInt("2402522289991562708547657")));
        EXPECT_EQ(false, BigPrimes::PseudoprimeTest::is_prime(BigPrimes::LongInt("21248545887928891474652335601565439")));
        EXPECT_EQ(false, BigPrimes::PseudoprimeTest::is_prime(BigPrimes::LongInt("90292588442483513836035511626516367608571235313731")));
        EXPECT_EQ(false, BigPrimes::PseudoprimeTest::is_prime(BigPrimes::LongInt("9872148080259252695739916128157688661281491869135186408257172754360211364033337611193632333415090857")));
    }
}
