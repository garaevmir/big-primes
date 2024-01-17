#pragma once

#include "main.h"
#include "pollard-rho.h"
#include "trial_division.h"
#include "print_functions.h"

bool run_lucas_test_for_primality(const main_type& number);

bool lucas_test_for_primality(const main_type& number, const main_type arg, const paired_vector& factorization);
