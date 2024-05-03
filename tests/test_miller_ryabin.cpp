#include "test_miller_ryabin.h"

namespace TestMillerRyabin {
    void test() {
        test_primes();
        test_composites();
    }

    void test_primes() {
        project::LongInt number;
        number = 179;
        assert(project::PseudoprimeTest::is_prime(number) == true);
        number = 41077;
        assert(project::PseudoprimeTest::is_prime(number) == true);
        number = 5941613819;
        assert(project::PseudoprimeTest::is_prime(number) == true);
        number = 313372252932373;
        assert(project::PseudoprimeTest::is_prime(number) == true);
        number = project::LongInt("48452878594687224547");
        assert(project::PseudoprimeTest::is_prime(number) == true);
        number = project::LongInt("9815155030774794504603661");
        assert(project::PseudoprimeTest::is_prime(number) == true);
        number = project::LongInt("27365084842452949020535457712834761");
        assert(project::PseudoprimeTest::is_prime(number) == true);
        number = project::LongInt("74997382925113036024802760153259410990097509328129");
        assert(project::PseudoprimeTest::is_prime(number) == true);
        number = project::LongInt("4299627456236271695097163499498705248885485007206706020942071089424297329292721947966917855975996661");
        assert(project::PseudoprimeTest::is_prime(number) == true);
    }

    void test_composites() {
        project::LongInt number;
        number = 342;
        assert(project::PseudoprimeTest::is_prime(number) == false);
        number = 90751;
        assert(project::PseudoprimeTest::is_prime(number) == false);
        number = 4339963843;
        assert(project::PseudoprimeTest::is_prime(number) == false);
        number = 93931233200855;
        assert(project::PseudoprimeTest::is_prime(number) == false);
        number = project::LongInt("75583811853085190253");
        assert(project::PseudoprimeTest::is_prime(number) == false);
        number = project::LongInt("2402522289991562708547657");
        assert(project::PseudoprimeTest::is_prime(number) == false);
        number = project::LongInt("21248545887928891474652335601565439");
        assert(project::PseudoprimeTest::is_prime(number) == false);
        number = project::LongInt("90292588442483513836035511626516367608571235313731");
        assert(project::PseudoprimeTest::is_prime(number) == false);
        number = project::LongInt("9872148080259252695739916128157688661281491869135186408257172754360211364033337611193632333415090857");
        assert(project::PseudoprimeTest::is_prime(number) == false);
    }
}
