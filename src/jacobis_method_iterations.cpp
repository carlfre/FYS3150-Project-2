#include "../include/jacobis_method_iterations.hpp"

std::vector<int> no_of_jacobi_iterations(std::vector<int> N_values_vector, double eps)
{
    int no_of_N_values = N_values_vector.size();
    int N, n;
    double h, a, d;
    arma::mat A;
    arma::vec eigenvalues;
    arma::mat eigenvectors;
    int maxiter, iterations;
    bool converged;

    std::vector<int> iterations_vector;
    for (int i= 0; i<no_of_N_values; i++)
    {
        //Generate matrix A
        N = N_values_vector[i];
        n = N + 1; // no. of intervals
        h = 1.0/n;
        a = -1.0/pow(h, 2);
        d = 2.0/(pow(h, 2));
        A = create_symmetric_tridiagonal(N, a, d);

        //Solve for eigenvalues + eigenvectors and keep track of iterations
        iterations = 0;
        maxiter = N*N*N;
        jacobi_eigensolver(A, eps, eigenvalues, eigenvectors, maxiter, iterations, converged);
        iterations_vector.push_back(iterations);
    }
    return iterations_vector;
}
