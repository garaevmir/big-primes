#include "tests.h"

using namespace BigPrimes;

int main() {
    TestMillerRyabin::test();
    TestLucas::test();
    TestTrialDivision::test();
    TestPollardRho::test();
    TestQuadraticSieve::test();
    return 0;
}
