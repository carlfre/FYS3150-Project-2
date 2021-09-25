#ifndef __jacobis_method_iterations__
#define __jacobis_method_iterations__

#include <armadillo>
#include <vector>

#include "create_tridiagonal.hpp"
#include "matrix_operations.hpp"

std::vector<int> no_of_jacobi_iterations(std::vector<int> N_values_vector, double eps);

#endif
