#include "test_lucas_primality.h"

using namespace BigPrimes;

namespace TestLucas {
    void test() {
        std::cout << "Testing Lucas primality test\n----------------------------------\n";
        test_primes();
        test_composites();
        std::cout << "==================================\n";
    }
    void test_primes() {
        std::cout << "Speed test for prime numbers\n";
        std::vector<LongInt> numbers{179, 41077, 5941613819, 313372252932373, LongInt("48452878594687224547"),
                                     LongInt("9815155030774794504603661"),
                                     LongInt("27365084842452949020535457712834761"),
                                     LongInt("62301430410880998312047688564794632198076683384721"),
                                     LongInt("4299627456236271695097163499498705248885485007206706020942071089424297329292721947966917855975996661")};
        auto function = &LucasPrimalityTest::is_prime;
        for (const auto& i : numbers) {
            time_measure(function, i);
        }
        std::cout << '\n';
    }
    void test_composites() {
        std::cout << "Speed test for composite numbers\n";
        std::vector<LongInt> numbers{342, 90751, 4339963843, 939312332008555, LongInt("75583811853085190253"),
                                     LongInt("2402522289991562708547657"),
                                     LongInt("21248545887928891474652335601565439")};
        auto function = &LucasPrimalityTest::is_prime;
        for (const auto& i : numbers) {
            time_measure(function, i);
        }
        std::cout << '\n';
    }
}
