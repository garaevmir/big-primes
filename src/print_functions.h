#pragma once

#include "defines.h"

namespace project {
    void print_pair_vector(const std::vector<factorization>& vec);
    template <typename T>
    void print_vector(const std::vector<T>& vec) {
        for (auto i : vec) {
            std::cout << i << ' ';
        }
        std::cout << '\n';
    }
}
