#include <iostream>
#include <cmath>

#include "create_tridiagonal.hpp"
#include "matrix_operations.hpp"
#include "test_matrix_operations.hpp"
#include "test_6_by_6_matrix.hpp"

int main(int argc, char *argv[]) {

    test_6_by_6_symmetric_find_eigenvalues_and_eigenvectors();
    test_max_offdiag_symmetric();
    return 0;
}
