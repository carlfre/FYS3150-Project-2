#include "../include/test_matrix.hpp"

//Tests that eigenvalues and vectors of matrix from
//create_symmetric_tridiagonal align with eigenvalues and 
//vectors computed with formula from project description
void test_symmetric_tridiagonal_eigenval_eigenvec()
{
    int N = 6; // no. of entries in matrix
    int n = N + 1; // no. of intervals
    double h = 1.0/n;
    arma::mat A = create_symmetric_tridiagonal(N, -1.0/pow(h, 2), 2.0/(pow(h, 2)));

    //find eigenvalues and eienvectors
    arma::vec eigval;
    arma::mat eigvec;
    eig_sym(eigval, eigvec, A);
    eigval.print();
    eigvec.print();
    assert (false);
}