#include "../include/test_matrix.hpp"

//checks whether two vectors are parallel
bool is_parallel(arma::vec v1, arma::vec v2);

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
        double eigval_analytical = d + 2*a*cos(i*M_PI/(N+1)); //from project descr.
        for (int j=0; j<N; j++)
        {
            if (abs(eigvals(j) - eigval_analytical) < tol)
            {
                is_eigval = true;
            }

        }
        assert (is_eigval);
    }

    //next check computed eigenvectors against analytical
    bool is_eigvec;
    for (int i=1; i<N+1; i++)
    {
        is_eigvec = false;
        arma::vec eigvec_analytical(N);
        for (int k=1; k<N+1; k++)
        {
            eigvec_analytical(k-1) = sin(k*i*M_PI/(N+1)); //from project descr.
        }
        for (int j=0; j<N; j++)
        {
            arma::vec eigvec_computed = eigvecs.col(j);
            if (is_parallel(eigvec_computed, eigvec_analytical))
            {
                is_eigvec = true;
            }
        }
        assert (is_eigvec);
    }
}

bool is_parallel(arma::vec v1, arma::vec v2)
{
    if (v1.n_elem != v2.n_elem)
    {
        return false;
    }

    int n = v1.n_elem;
    double ratio_1 = v2(0)/v1(0);
    double tol = abs(ratio_1) / 1e8;

    //if ratio between elements of vectors are unequal,
    //they're not parallell
    for (int i=1; i<n; i++)
    {
        double ratio_i = v2(i)/v1(i);
        std::cout << tol << " " << ratio_1 << " " << ratio_i << std::endl;
        if (abs(ratio_i - ratio_1) > tol)
        {
            std::cout << "hi" << std::endl;
            return false;
        }
    }
    //if all ratios are equal, vectors are parallel
    return true;
}