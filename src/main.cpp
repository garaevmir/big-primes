#include "defines.h"
#include "strong_pseudoprime_test.h"
#include "test_for_primality.h"
#include "trial_division.h"
#include "quadratic_sieve.h"
#include "pollard-rho.h"
#include <chrono>

int main() {
    project::LongInt num;
//    project::LongInt a;
//    std::cin >> a;
//    project::SmallType b = 15000;
//    project::SmallType c = 100000000;
//    project::QuadraticSieve abc(a, b, c);
//    abc.factor_one();
//    std::cout << "**********\n";
//    return 0;
//    auto saa = abc.find_congruences(17);
//    project::print_vector(saa);
    std::cout << "Write an integer number to examine it\n";
    std::cin >> num;
    std::cout << num << '\n';
    if (project::PseudoprimeTest::is_prime(num)) {
        std::cout << "Strong probable prime\n";
        if (project::LucasPrimalityTest::is_prime(num)) {
            std::cout << "Prime number\n";
        } else {
            std::cout << "Composite number\n";
        }
    }
    else {
        std::cout << "Not a prime\nWould you like to calculate factorization of a number? [y/n]\n";
        std::string answer;
        std::cin >> answer;
        if (answer == "y") {
            auto start = std::chrono::high_resolution_clock::now();
//            auto factors = project::PollardRho::factorize(num);
            project::SmallType b = 2000;
            project::SmallType c = 100000;
            project::QuadraticSieve abc(num, b, c);
            auto factors = abc.factor_one(num);
            project::LongInt a = 1;
//            auto factors = project::TrialDivision::factor_one(num);
            std::cout << factors << '\n';
            auto end = std::chrono::high_resolution_clock::now();
            auto time_elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
            std::cout << "Time consumed: " << time_elapsed.count() << " ms" << std::endl;
            std::cout << "Your factorization:\nPrime Degree\n";
//            for (const auto& i : factors) {
//                std::cout << i.first << ' ' << i.second << '\n';
//            }
        }
    }
}
