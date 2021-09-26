#ifndef __jacobis_method_iterations__
#define __jacobis_method_iterations__

#include <armadillo>
#include <vector>

#include "create_tridiagonal.hpp"
#include "matrix_operations.hpp"

//N_values_vector contains values of N we want to run Jacobi's rot. method for
//eps is the tolerance for maximal offdiagonal element for Jacobis rot. method
//returns vector with number of iterations used for each N
std::vector<int> no_of_jacobi_iterations(std::vector<int> N_values_vector, double eps);

#endif
