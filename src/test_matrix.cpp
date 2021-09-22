#include "../include/test_matrix.hpp"

//Tests that eigenvalues and vectors of matrix from
//create_symmetric_tridiagonal align with eigenvalues and 
//vectors computed with formula from project description
void test_symmetric_tridiagonal_eigenval_eigenvec()
{
    int N = 6; // no. of entries in matrix
    int n = N + 1; // no. of intervals
    double h = 1.0/n;
    double a = -1.0/pow(h, 2);
    double d = 2.0/(pow(h, 2));
    arma::mat A = create_symmetric_tridiagonal(N, a, d);

    //find eigenvalues and eigenvectors of A
    arma::vec eigvals;
    arma::mat eigvecs;
    eig_sym(eigvals, eigvecs, A);

    //first check that computed eigenvalues are the same as those
    //from analytical solution
    double tol = 1e-8;
    bool is_eigval;
    for (int i=1; i<N+1; i++)
    {
        is_eigval = false;
        double eigval_analytical = d + 2*a*cos(i*M_PI/(N+1));
        for (int j=0; j<N; j++)
        {
            if (abs(eigvals(j) - eigval_analytical) < tol)
            {
                is_eigval = true;
            }

        }
        assert (is_eigval);
    }
    
}