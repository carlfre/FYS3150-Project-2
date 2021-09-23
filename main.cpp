#include <iostream>

#include "create_tridiagonal.hpp"
#include "matrix_operations.hpp"
#include "test_matrix_operations.hpp"

int main(int argc, char *argv[]) {
    test_max_offdiag_symmetric();
    return 0;
}