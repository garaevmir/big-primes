#include "print_functions.h"

namespace project {
    void print_pair_vector(const std::vector<factorization>& vec) {
        for (auto i : vec) {
            std::cout << i.divisor << ' ' << i.degree << '\n';
        }
        std::cout << '\n';
    }
    }
