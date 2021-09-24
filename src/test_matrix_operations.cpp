#include "../include/test_matrix_operations.hpp"
#include "../include/matrix_operations.hpp"

// Test of matrix from 4b)
void test_max_offdiag_symmetric()
{
    arma::mat A;
    A << 1 << 0 << 0 << 0.5 << arma::endr
      << 0 << 1 << -0.7 << 0 << arma::endr
      << 0 << -0.7 << 1 << 0 << arma::endr
      << 0.5 << 0 << 0 << 1 << arma::endr;

    int k; //row index
    int l; //col index
    double max_val = max_offdiag_symmetric(A, k, l);
    //expecting "0.7 1 2"
    std::cout << max_val << " " << k << " " << l << std::endl;
}
