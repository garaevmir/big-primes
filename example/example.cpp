#include "defines.h"
#include "strong_pseudoprime_test.h"
#include "test_for_primality.h"
#include "trial_division.h"
#include "quadratic_sieve.h"
#include "pollard-rho.h"
#include <chrono>

int main() {
    project::LongInt num;
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
            project::QuadraticSieve abc(num);
            auto factors = abc.factorize(num);
            std::cout << "Your factorization:\nPrime Degree\n";
            for (const auto& i : factors) {
                std::cout << i.first << ' ' << i.second << '\n';
            }
        }
    }
}
