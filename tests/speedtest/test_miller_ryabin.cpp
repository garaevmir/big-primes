#include "test_miller_ryabin.h"

using namespace BigPrimes;

namespace TestMillerRyabin {
    void test() {
        std::cout << "Testing Miller-Ryabin test\n----------------------------------\n";
        test_primes();
        test_composites();
        std::cout << "==================================\n";
    }
    void test_primes() {
        std::cout << "Speed test for prime numbers\n";
        std::vector<LongInt> numbers{179, 41077, 5941613819, 313372252932373, LongInt("48452878594687224547"),
                                     LongInt("9815155030774794504603661"),
                                     LongInt("27365084842452949020535457712834761"),
                                     LongInt("74997382925113036024802760153259410990097509328129"),
                                     LongInt("4299627456236271695097163499498705248885485007206706020942071089424297329292721947966917855975996661")};
        auto function = &PseudoprimeTest::is_prime;
        for (const auto& i : numbers) {
            time_measure(function, i);
        }
        std::cout << '\n';
    }
    void test_composites() {
        std::cout << "Speed test for composite numbers\n";
        std::vector<LongInt> numbers{342, 90751, 4339963843, 939312332008555, LongInt("75583811853085190253"),
                                     LongInt("2402522289991562708547657"),
                                     LongInt("21248545887928891474652335601565439"),
                                     LongInt("90292588442483513836035511626516367608571235313731"),
                                     LongInt("9872148080259252695739916128157688661281491869135186408257172754360211364033337611193632333415090857")};
        auto function = &PseudoprimeTest::is_prime;
        for (const auto& i : numbers) {
            time_measure(function, i);
        }
        std::cout << '\n';
    }
}
