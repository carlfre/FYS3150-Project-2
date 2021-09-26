#include "../include/test_6_by_6_matrix.hpp"

//Tests that eigenvalues and vectors of matrix from
//create_symmetric_tridiagonal align with eigenvalues and 
//vectors computed with formula from project description
void test_6_by_6_symmetric_find_eigenvalues_and_eigenvectors()
{
    //This function creates an example tridiagonal matrix and prints 
    //eigenvalues and eigenvectors from eig_sym-function, analytical formula,
    //and Jacobi's rotation method, such that we can verify they are the same
    //Note: eigenvectors are stored as columns in matrices

    int N = 6; // no. of entries in matrix
    int n = N + 1; // no. of intervals
    double h = 1.0/n;
    double a = -1.0/pow(h, 2);
    double d = 2.0/(pow(h, 2));
    arma::mat A = create_symmetric_tridiagonal(N, a, d);

    //find eigenvalues and eigenvectors of A with eig_sym
    arma::vec eigvals_eigsym;
    arma::mat eigvecs_eigsym;
    eig_sym(eigvals_eigsym, eigvecs_eigsym, A);
    //normalise eigenvectors computed with eig_sym
    for (int i=0; i<N; i++)
    {
        eigvecs_eigsym.col(i) = arma::normalise(eigvecs_eigsym.col(i));
    }

    //Compute eigenvalues and eigenvectors with Jacobi's rotation method
    double eps = 1e-8;
    arma::vec eigvals_jacobi;
    arma::mat eigvecs_jacobi;
    int maxiter = 100;
    int iterations;
    bool converged;
    jacobi_eigensolver(A, eps, eigvals_jacobi, eigvecs_jacobi, maxiter, iterations, converged);

    //Compute eigenvalues with analytical formula
    arma::vec eigvals_analytical(N);
    for (int i=1; i<N+1; i++)
    {
        eigvals_analytical(i-1) = d + 2*a*cos(i*M_PI/(N+1)); //from project descr.
    }

    //Compute eigenvectors with analytical formula
    arma::mat eigvecs_analytical(N, N);
    arma::vec eigvec_analytical(N);
    for (int i=1; i<N+1; i++) 
    {
        for (int k=1; k<N+1; k++)
        {
            eigvec_analytical(k-1) = sin(k*i*M_PI/(N+1));
        }
        //normalise eigenvector
        eigvecs_analytical.col(i-1) =  arma::normalise(eigvec_analytical);
    }

    //Print eigenvalues to compare
    std::cout << "Eigenvalues with eig_sym-function:" << std::endl;
    eigvals_eigsym.print();
    std::cout << "Eigenvalues with Jacobi's rotation method:" << std::endl;
    eigvals_jacobi.print();
    std::cout << "Eigenvalues with analytical formula:" << std::endl;
    eigvals_analytical.print();

    //print eigenvectors to compare
    std::cout << "Eigenvectors with eig_sym-function:" << std::endl;
    eigvecs_eigsym.print();
    std::cout << "Eigenvectors with Jacobi's rotation method:" <<std::endl;
    eigvecs_jacobi.print();
    std::cout << "Eigenvectors with analytical formula:" << std::endl;
    eigvecs_analytical.print();
}
