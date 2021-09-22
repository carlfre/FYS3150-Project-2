#include "../include/create_tridiagonal.hpp"

// Create tridiagonal matrix from vectors.
// - lower diagonal: vector a, lenght n-1
// - main diagonal:  vector d, lenght n
// - upper diagonal: vector e, lenght n-1
arma::mat create_tridiagonal(const arma::vec& a, const arma::vec& d,const arma::vec& e)
{
    // Start from identity matrix
    int N = d.n_elem;
    arma::mat A = arma::mat(N, N, arma::fill::eye);
    
    // Fill first row (row index 0)
    A(0, 0) = d(0);
    A(0, 1) = e(0);

    // Loop that fills rows 2 to n-1 (row indices 1 to n-2)
    for (int i = 1;i < N-1; i++)
    {
        A(i, i-1) = a(i-1);
        A(i, i) = d(i);
        A(i, i+1) = e(i);
    }

    // Fill last row (row index n-1)
    A(N-1, N-2) = a(N-2);
    A(N-1, N-1) = d(N-1);

    //arma::mat A; //hvorfor?
    return A;
}


// Create a tridiagonal matrix tridiag(a,d,e) of size N*N
// from scalar input a, d and e
arma::mat create_tridiagonal(int N, double a, double d, double e)
{
    arma::vec a_vec = arma::vec(N-1, arma::fill::ones) * a;
    arma::vec d_vec = arma::vec(N, arma::fill::ones) * d;
    arma::vec e_vec = arma::vec(N-1, arma::fill::ones) * e;

    // Call the vector version of this function and return the result
    return create_tridiagonal(a_vec, d_vec, e_vec);
}


// Create a symmetric tridiagonal matrix tridiag(a,d,a) of size n*n
// from scalar input a and d.
arma::mat create_symmetric_tridiagonal(int N, double a, double d)
{
    // Call create_tridiagonal and return the result
    return create_tridiagonal(N, a, d, a);
}
