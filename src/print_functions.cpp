#include "print_functions.h"

void print_pair_vector(paired_vector vec) {
    for (auto i : vec) {
        std::cout << i.first << ' ' << i.second << '\n';
    }
    std::cout << '\n';
}
