#include "main.h"
#include "strong_pseudoprime_test.h"
#include "test_for_primality.h"
#include "print_functions.h"
#include "trial_division.h"

int main() {
    main_type num;
    std::cout << "Write an integer number to examine it\n";
    std::cin >> num;
    std::cout << num << '\n';
    if (run_strong_pseudoprime_test(num)) {
        std::cout << "Strong probable prime\n";
        if (run_lucas_test_for_primality(num)) {
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
            paired_vector factorization = run_trial_division(num);
            std::cout << "Your factorization:\nPrime Degree\n";
            print_pair_vector(factorization);
        }
    }
}
