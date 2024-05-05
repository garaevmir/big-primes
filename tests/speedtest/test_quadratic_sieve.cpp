#include "test_quadratic_sieve.h"

using namespace project;

namespace TestQuadraticSieve {
    void test() {
        std::cout << "Testing Quadratic Sieve\n----------------------------------\n";
        test_factor_one();
        test_factorization();
        std::cout << "==================================\n";
    }

    void test_time_qs(const LongInt& number) {
    }

    void test_factor_one() {
        std::cout << "Speed test for one factor\n";
        std::vector<LongInt> numbers{705, 45023, 1097010613, 397166490301909, LongInt("10692119085417692189"),
                                     LongInt("1340739765032470240000933"),
                                     LongInt("44740747869931444455739288444731585052051587564941")};
        for (auto i : numbers) {
            project::SmallType digits = 0;
            project::LongInt temp = i;
            while (temp > 0) {
                ++digits;
                temp /= 10;
            }
            QuadraticSieve exe(i);
            auto start = std::chrono::high_resolution_clock::now();
            exe.factor_one(i);
            auto end = std::chrono::high_resolution_clock::now();
            auto time_elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
            std::cout << "Time consumed for " << digits <<" digit number: " << time_elapsed.count() << " ms\n";
        }
        std::cout << '\n';
    }

    void test_factorization() {
        std::cout << "Speed test for factorisation\n";
        std::vector<LongInt> numbers{705, 45023, 1097010613, 397166490301909, LongInt("10692119085417692189"),
                                     LongInt("1340739765032470240000933"),
                                     LongInt("44740747869931444455739288444731585052051587564941")};
        for (auto i : numbers) {
            project::SmallType digits = 0;
            project::LongInt temp = i;
            while (temp > 0) {
                ++digits;
                temp /= 10;
            }
            QuadraticSieve exe(i);
            auto start = std::chrono::high_resolution_clock::now();
            exe.factorize(i);
            auto end = std::chrono::high_resolution_clock::now();
            auto time_elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
            std::cout << "Time consumed for " << digits <<" digit number: " << time_elapsed.count() << " ms\n";
        }
        std::cout << '\n';
    }
}

