#include "trial_division.h"

bool trial_division_test(main_type number) {
    if (number % 2 == 0 && number != 2) {
        return false;
    }
    for (main_type i = 3; i < sqrt(number) + 1; i += 2) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

main_type trial_division(main_type number, main_type start) {
    for (main_type i = start + 1; i < sqrt(number) + 1; i += 2) {
        if (number % i == 0) {
            return i;
        }
    }
    return number;
}
paired_vector run_trial_division(main_type number) {
    main_type answer;
    main_type last = 2;
    paired_vector factorization;
    if (number % 2 == 0) {
        answer = 2;
        factorization.push_back({ 2, 0 });
        while (number % answer == 0) {
            number /= answer;
            ++factorization[0].second;
        }
    }
    while (number != 1) {
        answer = trial_division(number, last);
        main_type deg = 0;
        while (number % answer == 0) {
            number /= answer;
            ++deg;
        }
        factorization.push_back({ answer, deg });
    }
    return factorization;
}