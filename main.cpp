#include <iostream>
#include <cmath>

#include "create_tridiagonal.hpp"
#include "matrix_operations.hpp"

using namespace std;

int main(int argc, char *argv[]) 
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
    return 0;
}