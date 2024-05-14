#include "test_for_primality.h"
#include <gtest/gtest.h>

namespace Test {
    TEST(LucasPrimalityTest, Primes) {
        EXPECT_EQ(true, BigPrimes::LucasPrimalityTest::is_prime(179));
        EXPECT_EQ(true, BigPrimes::LucasPrimalityTest::is_prime(41077));
        EXPECT_EQ(true, BigPrimes::LucasPrimalityTest::is_prime(5941613819));
        EXPECT_EQ(true, BigPrimes::LucasPrimalityTest::is_prime(313372252932373));
        EXPECT_EQ(true, BigPrimes::LucasPrimalityTest::is_prime(BigPrimes::LongInt("48452878594687224547")));
        EXPECT_EQ(true, BigPrimes::LucasPrimalityTest::is_prime(BigPrimes::LongInt("9815155030774794504603661")));
        EXPECT_EQ(true, BigPrimes::LucasPrimalityTest::is_prime(BigPrimes::LongInt("27365084842452949020535457712834761")));
        EXPECT_EQ(true, BigPrimes::LucasPrimalityTest::is_prime(BigPrimes::LongInt("62301430410880998312047688564794632198076683384721")));
        EXPECT_EQ(true, BigPrimes::LucasPrimalityTest::is_prime(BigPrimes::LongInt("4299627456236271695097163499498705248885485007206706020942071089424297329292721947966917855975996661")));
    }
    TEST(LucasPrimalityTest, Composites) {
        EXPECT_EQ(false, BigPrimes::LucasPrimalityTest::is_prime(342));
        EXPECT_EQ(false, BigPrimes::LucasPrimalityTest::is_prime(90751));
        EXPECT_EQ(false, BigPrimes::LucasPrimalityTest::is_prime(4339963843));
        EXPECT_EQ(false, BigPrimes::LucasPrimalityTest::is_prime(93931233200855));
        EXPECT_EQ(false, BigPrimes::LucasPrimalityTest::is_prime(BigPrimes::LongInt("75583811853085190253")));
        EXPECT_EQ(false, BigPrimes::LucasPrimalityTest::is_prime(BigPrimes::LongInt("2402522289991562708547657")));
        EXPECT_EQ(false, BigPrimes::LucasPrimalityTest::is_prime(BigPrimes::LongInt("21248545887928891474652335601565439")));
    }
}
