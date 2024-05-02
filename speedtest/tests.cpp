#include "tests.h"

using namespace project;

int main() {
    TestMillerRyabin::test();
    TestLucas::test();
    TestTrialDivision::test();
    TestPollardRho::test();
    TestQuadraticSieve::test();
    return 0;
}
