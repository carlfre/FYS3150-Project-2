#include "../include/test_matrix.hpp"

//Tests that eigenvalues and vectors of matrix from
//create_symmetric_tridiagonal align with eigenvalues and 
//vectors computed with formula from project description
void test_6_by_6_symmetric_with_eig_sym()
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
    //eigvecs.print();
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

    //Set values of analytical eigenvectors as row in matrix. Normalise
    arma::mat eigvecs_analytical(N, N);
    arma::vec eigvec_analytical(N);
    for (int i=1; i<N+1; i++) //
    {
        for (int k=1; k<N+1; k++)
        {
            eigvec_analytical(k-1) = sin(k*i*M_PI/(N+1)); //from project descr.
        }
        eigvecs_analytical.col(i-1) =  arma::normalise(eigvec_analytical);
    }

    //normalise vectors from computed solution from eig_sym
    for (int i=0; i<N; i++)
    {
        eigvecs.col(i) = arma::normalise(eigvecs.col(i));
    }
    std::cout << "Analytical eigenvectors are columns of following matrix" << std::endl;
    eigvecs_analytical.print();
    std::cout << "Eigenvectors computed with eig_sym are columns of following matrix" << std::endl;
    eigvecs.print();
    //if analytical and computed vectors are parallel, we are happy:)
}
