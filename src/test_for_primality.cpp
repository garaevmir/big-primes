#include "test_for_primality.h"

bool run_lucas_test_for_primality(const main_type& number) {
	paired_vector factorization = run_trial_division(number - 1);
	main_type limit = main_type(log(boost::multiprecision::cpp_dec_float_100(number))) + 1;
	bool flag = true;
	limit *= limit;
	limit = min(limit * limit * limit, number);
	if (lucas_test_for_primality(number, 2, factorization)) {
		return true;
	}
	for (main_type i = 3; i < limit; i += 2) {
		if (lucas_test_for_primality(number, i, factorization)) {
			return true;
		}
	}
	return false;
}

bool lucas_test_for_primality(const main_type& number, const main_type arg, const paired_vector& factorization) {
	if (fast_degree_module(arg, number - 1, number) == 1) {
		bool flag = true;
		for (std::pair<main_type, main_type> j : factorization) {
			if (fast_degree_module(arg, (number - 1) / j.first, number) == 1) {
				flag = false;
				break;
			}
		}
		if (flag) {
			return true;
		}
	}
	return false;
}
