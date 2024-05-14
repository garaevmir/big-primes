#include "defines.h"
#include "strong_pseudoprime_test.h"
#include "test_for_primality.h"
#include "trial_division.h"
#include "quadratic_sieve.h"
#include "pollard-rho.h"

int main() {
    BigPrimes::LongInt num;
    std::cout << "Write an integer number to examine it\n";
    std::cin >> num;
    std::cout << num << '\n';
    if (BigPrimes::PseudoprimeTest::is_prime(num)) {
        std::cout << "Strong probable prime\n";
        if (BigPrimes::LucasPrimalityTest::is_prime(num)) {
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
            BigPrimes::QuadraticSieve qs(num);
            auto factors = qs.factorize(num);
            std::cout << "Your factorization:\nPrime Degree\n";
            for (const auto& i : factors) {
                std::cout << i.first << ' ' << i.second << '\n';
            }
        }
    }
}
