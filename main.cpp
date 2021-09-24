#include <iostream>
#include <cmath>

#include "create_tridiagonal.hpp"
#include "matrix_operations.hpp"
#include "test_matrix_operations.hpp"
#include "test_matrix.hpp"

int main(int argc, char *argv[]) {

    test_6_by_6_symmetric_with_eig_sym();
    test_max_offdiag_symmetric();
    return 0;
}
