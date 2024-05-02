#include "test_pollard_rho.h"

using namespace project;

namespace TestPollardRho {
    void test() {
        std::cout << "Testing Pollard Rho\n----------------------------------\n";
        test_factor_one();
        test_factorization();
        std::cout << "==================================\n";
    }

    void test_factor_one() {
        std::cout << "Speed test for one factor\n";
        std::vector<LongInt> numbers{705, 45023, 1097010613, 397166490301909, LongInt("10692119085417692189"),
                                     LongInt("1340739765032470240000933"),
                                     LongInt("57388947496693346193146341306536502913894044311157"),
        LongInt("4587592344173103261443900376261941495420442936345693512940254899327042718929338589101567099577384933")};
        auto function = &PollardRho::factor_one;
        for (auto i : numbers) {
            time_measure(function, i);
        }
        std::cout << '\n';
    }

    void test_factorization() {
        std::cout << "Speed test for factorisation\n";
        std::vector<LongInt> numbers{705, 45023, 1097010613, 397166490301909, LongInt("10692119085417692189"),
                                     LongInt("1340739765032470240000933"),
                                     LongInt("57388947496693346193146341306536502913894044311157"),
        LongInt("4587592344173103261443900376261941495420442936345693512940254899327042718929338589101567099577384933")};
        auto function = &PollardRho::factorize;
        for (auto i : numbers) {
            time_measure(function, i);
        }
        std::cout << '\n';
    }
}
