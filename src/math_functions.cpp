#include "math_functions.h"

main_type fast_degree_module(const main_type num, const main_type deg, const main_type module) {
    if (deg == 0) {
        return 1;
    }
    if (deg % 2 == 1) {
        return (fast_degree_module(num, deg - 1, module) * num) % module;
    }
    main_type ans = fast_degree_module(num, deg / 2, module);
    return (ans * ans) % module;
}

main_type gcd(main_type a, main_type b) {
    if (b == 0) {
        return a;
    }
    a = a % b;
    return gcd(b, a);
}
