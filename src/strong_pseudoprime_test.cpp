#include "strong_pseudoprime_test.h"

bool run_strong_pseudoprime_test(const main_type& number) {
	small_type number_length = 0;
	main_type temp = number;
	while (temp) {
		temp /= 10;
		++number_length;
	}
	number_length *= number_length;
	temp = 1;
	while (number_length > 0) {
		for (main_type i = temp + 2; i < number; i += 2) {
			if (number % i != 0) {
				temp = i;
				break;
			}
		}
		if (!strong_pseudoprime_test(number, temp)) {
			return false;
		}
		--number_length;
	}
	return true;
}

bool strong_pseudoprime_test(const main_type& number, const main_type& prime_to_number) {
	main_type temp = number - 1;
	main_type two_degree = 0;
	while (temp % 2 == 0) {
		temp /= 2;
		++two_degree;
	}
	temp = fast_degree_module(prime_to_number, temp, number);
	if (temp == 1 || temp == number - 1) {
		return true;
	}
	for (main_type i = 1; i < two_degree; ++i) {
		temp = (temp * temp) % number;
		if (temp == number - 1) {
			return true;
		}
	}
	return false;
}
