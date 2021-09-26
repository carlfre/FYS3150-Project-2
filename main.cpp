#include <iostream>
#include <cmath>
#include <vector>

#include "create_tridiagonal.hpp"
#include "matrix_operations.hpp"
#include "test_matrix_operations.hpp"
#include "test_6_by_6_matrix.hpp"
#include "jacobis_method_iterations.hpp"
#include "write_to_file.hpp"

int main(int argc, char *argv[]) {
    //test_6_by_6_symmetric_find_eigenvalues_and_eigenvectors();
    //test_max_offdiag_symmetric();

    //Calculate no. of Jacobi rotations for each N and write to file
    std::vector<int> N_values{2, 4, 8, 16, 32, 64, 128, 256};
    double eps = 1e-8;
    std::vector<int> iterations_vec = no_of_jacobi_iterations(N_values, eps);
    std::string filename ("csv/number_of_iterations.csv");
    write_two_integer_vectors_to_file(filename, N_values, iterations_vec);
    return 0;
}
