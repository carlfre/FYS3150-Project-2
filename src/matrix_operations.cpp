#include "../include/matrix_operations.hpp"

// A function that finds the max off-diag element of a symmetric matrix A.
// - The matrix indices of the max element are returned by writing to the  
//   int references k and l (row and column, respectively)
// - The value of the max element A(k,l) is returned as the function
//   return value
double max_offdiag_symmetric(const arma::mat& A, int& k, int& l)
{
    // Get size of the matrix A. Use e.g. A.n_rows, see the Armadillo documentation

    // Possible consistency checks:
    // Check that A is square and larger than 1x1. Here you can for instance use A.is_square(), 
    // see the Armadillo documentation.
    // 
    // The standard function 'assert' from <assert.h> can be useful for quick checks like this 
    // during the code development phase. Use it like this: assert(some condition),
    // e.g assert(a==b). If the condition evaluates to false, the program is killed with 
    // an assertion error. More info: https://www.cplusplus.com/reference/cassert/assert/

    // Initialize references k and l to the first off-diagonal element of A

    // Initialize a double variable 'maxval' to A(k,l). We'll use this variable 
    // to keep track of the largest off-diag element.

    // Loop through all elements in the upper triangle of A (not including the diagonal)
    // When encountering a matrix element with larger absolute value than the current value of maxval,
    // update k, l and max accordingly.

    // Return maxval
    double max = 0.0;
    int n = A.n_cols;
    for ( int i = 0; i < n; i++ ) 
    {
        for ( int j = i+1; j < n; j++) 
        {
            if (fabs(A(i,j)) > max )
            {
                max = fabs(A(i,j));
                k = i;
                l = j;
             }
        }
    }
    return max;
}

void jacobi_rotate(arma::mat& A, arma::mat& R, int k, int l)
{
    //Performs one jacobi rotation of angle theta to set A(k,l)=A(l, k)=0.
    //First computes sin(theta), cos(theta). Then performs rotation and
    //calculates product of rotation matrices (which gives approximation
    //for eigenvectors of A).
    const int N = A.n_cols;
    double s, c, t; //values of sin(theta), cos(theta), tan(theta)
    double tau = (A(l, l) - A(k, k))/(2*A(k,l)); //Assuming A(k, l) != 0
    if (tau>0)
    {
        t = 1.0/(tau + sqrt(tau*tau + 1));
    }
    else
    {
        t = -1.0/(-tau + sqrt(tau*tau + 1));
    }
    c = 1/(sqrt(t*t + 1));
    s = c*t;
    //set values of rotated matrix A
    double A_kk = A(k, k);
    double A_ll = A(l, l);
    double A_kl = A(k, l);

    A(k, k) = c*c*A_kk - 2*s*c*A_kl + s*s*A_ll;
    A(l, l) = s*s*A_kk + 2*s*c*A_kl + c*c*A_ll;
    A(k, l) = 0; //Rotate to set equal to 0
    A(l, k) = 0;

    for (int i = 0; i<N; i++)
    {
        //Compute all other new entries in rotated A
        if ((i != k) && (i != l))
        {
            double A_ki = A(k, i);
            double A_li = A(l, i);
            A(k, i) = c*A_ki - s*A_li;
            A(i, k) = A(k, i);
            A(l, i) = s*A_ki + c*A_li;
            A(i, l) = A(l, i);
        }
        //Compute new approximation for eigenvectors
        double R_ik = R(i,k);
        double R_il = R(i,l);
        R(i,k) = c*R_ik - s*R_il;
        R(i,l) = c*R_il + s*R_ik;
    }
}

void jacobi_eigensolver(arma::mat& A, double eps, arma::vec& eigenvalues, arma::mat& eigenvectors,
                        const int maxiter, int& iterations, bool& converged)
{
    //Uses Jacobi's rotation method to find eigenvalues+vectors of matrix A.
    //Repeatedly applies Jacobi rotations until the matrix has been diagonalized.
    const int N = A.n_cols;
    eigenvectors.eye(N,N); 
    int k = 0;
    int l = 0;
    double maxoffdiag = max_offdiag_symmetric(A, k, l);
    iterations = 0;

    while ((maxoffdiag > eps) && (iterations < maxiter)) 
    {
        jacobi_rotate(A, eigenvectors, k, l);
        iterations++;
        maxoffdiag = max_offdiag_symmetric(A, k, l);
    }
    converged = (iterations < maxiter);
    eigenvalues = arma::diagvec(A);

    //sort eigenvectors
    arma::uvec sorting_indices = arma::sort_index(eigenvalues);
    arma::mat temp = eigenvectors;
    for (int i=0; i<N; i++)
    {
        int old_index = sorting_indices(i);
        eigenvectors.col(i) = temp.col(old_index);

    }
    //sort eigenvalues
    eigenvalues = arma::sort(eigenvalues);
}
