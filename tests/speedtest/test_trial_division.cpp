#include "test_trial_division.h"

using namespace BigPrimes;

namespace TestTrialDivision {
    void test() {
        std::cout << "Testing Trial Division\n----------------------------------\n";
        test_factor_one();
        test_factorization();
        std::cout << "==================================\n";
    }

    void test_factor_one() {
        std::cout << "Speed test for one factor\n";
        std::vector<LongInt> numbers{705, 45023, 1097010613, 397166490301909, LongInt("10692119085417692189"),
                                     LongInt("1340739765032470240000933"),
                                     LongInt("57388947496693346193146341306536502913894044311157")};
        auto function = &TrialDivision::factor_one;
        for (auto i : numbers) {
            time_measure(function, i);
        }
        std::cout << '\n';
    }

    void test_factorization() {
        std::cout << "Speed test for factorisation\n";
        std::vector<LongInt> numbers{705, 45023, 1097010613, 397166490301909, LongInt("10692119085417692189"),
                                     LongInt("1340739765032470240000933"),
                                     LongInt("57388947496693346193146341306536502913894044311157")};
        auto function = &TrialDivision::factorize;
        for (auto i : numbers) {
            time_measure(function, i);
        }
        std::cout << '\n';
    }
}
