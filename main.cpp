#include <iostream>
#include <cmath>
#include <vector>

#include "create_tridiagonal.hpp"
#include "matrix_operations.hpp"
#include "test.hpp"
#include "jacobis_method_iterations.hpp"
#include "write_to_file.hpp"

int main(int argc, char *argv[]) {
    if (strcmp(argv[1], "test") == 0)
    {
        //problem 3, problem 5
        test_6_by_6_symmetric_find_eigenvalues_and_eigenvectors();
        //problem 4
        test_max_offdiag_symmetric();
    }
    if (strcmp(argv[1], "problem6") == 0)
    {
        //Calculate no. of Jacobi rotations for each N and write to file
        std::vector<int> N_values {2, 4, 8, 16, 32, 64, 128, 256};
        double eps = 1e-8;
        std::vector<int> iterations_vec = no_of_jacobi_iterations(N_values, eps);
        std::string filename ("data/number_of_iterations.csv");
        write_two_integer_vectors_to_file(filename, N_values, iterations_vec);
    }
    if (strcmp(argv[1], "problem7") == 0)
    {
        std::vector<std::string> filenames { "data/3_eigvecs_n_equals_10.csv", 
                                            "data/3_eigvecs_n_equals_100.csv"};
        std::vector<int> N_values { 10, 100 };
        int no_of_N_values = N_values.size();
        arma::vec first_3_eigenvalues(3);

        int N, n;
        double h, a, d;
        arma::mat A;
        arma::vec eigenvalues;
        arma::mat eigenvectors;
        int maxiter, iterations;
        bool converged;
        double eps = 1e-8;

        for (int i=0; i<no_of_N_values; i++)
        {
            //Generate matrix A
            N = N_values[i];
            n = N + 1; // no. of intervals
            h = 1.0/n;
            a = -1.0/pow(h, 2);
            d = 2.0/(pow(h, 2));
            A = create_symmetric_tridiagonal(N, a, d);

            //Solve for eigenvalues + eigenvectors
            iterations = 0;
            maxiter = N*N*N;
            jacobi_eigensolver(A, eps, eigenvalues, eigenvectors, maxiter, iterations, converged);

            //write first 3 eigenvectors to file (corresponding to 3 lowest eigenvalues)
            for (int i=0; i<3; i++)
            {
                first_3_eigenvalues(i) = eigenvalues(i);
            }
            write_3_armadillo_vectors_to_file(filenames[i], first_3_eigenvalues, eigenvectors.col(0),
                                            eigenvectors.col(1), eigenvectors.col(2));
        }
    }
    return 0;
}
