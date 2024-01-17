#pragma once

#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

using main_type = boost::multiprecision::cpp_int;

using small_type = int;

using paired_vector = std::vector<std::pair<main_type, main_type>>;
