#ifndef __matrix_operations__
#define __matrix_operations__

#include <armadillo>

// Determine the the max off-diagonal element of a symmetric matrix A
// - Saves the matrix element indicies to k and l
// - Returns absolute value of A(k,l) as the function return value
double max_offdiag_symmetric(const arma::mat& A, int& k, int& l);


// Performs a single Jacobi rotation, to "rotate away"
// the off-diagonal element at A(k,l).
// - Assumes symmetric matrix, so we only consider k < l
// - Modifies the input matrices A and R
void jacobi_rotate(arma::mat& A, arma::mat& R, int k, int l);

// Jacobi method eigensolver:
// - Runs jacobo_rotate until max off-diagonal element < eps
// - Writes the eigenvalues as entries in the vector "eigenvalues"
// - Writes the eigenvectors as columns in the matrix "eigenvectors"
//   (The returned eigenvalues and eigenvectors are sorted using arma::sort_index)
// - Stops if it the number of iterations reaches "maxiter"
// - Writes the number of iterations to the integer "iterations"
// - Sets the bool reference "converged" to true if convergence was reached before hitting maxiter
void jacobi_eigensolver(const arma::mat& A, double eps, arma::vec& eigenvalues, arma::mat& eigenvectors,
                        const int maxiter, int& iterations, bool& converged);

#endif

// Test of matrix from 4b)
int main()
{
  int k = 0;
  int l = 0;

  int N = 4;

  arma::mat A;
  A << 1 << 0 << 0 << 0.5 << endr
    << 0 << 1 << -0.7 << 0 << endr
    << 0 << -0.7 << 1 << 0 << endr
    << 0.5 << 0 << 0 << 1 << endr;

  //A.print("A=");

  mat R;
  R.eye(N,N);

  max_offdiag_symmetric(A, k, l);
  return 0;
}

void jacobi_eigensolver(arma::mat& A, arma::vec& eigenvalues, arma::mat& eigenvectors, const int maxiter, int& iterations)
{
  int n = sqrt(A.size());
  mat R;
  R.eye(n,n);
  int k = 0;
  int l = 0;
  double eps = 1.0e-8;
  double maxoffdiag = max_offdiag_symmetric(A, k, l, n);


  while ( abs(maxoffdiag) > eps && iterations < maxiter) {
    jacobi_rotate(A, R, k, l);
    iterations++;
  }
  //cout << "Nub of iter:" << iterations <<"\n";
  return;

}

double max_offdiag_symmetric(const arma::mat& A, int& k, int& l, int n)
{
  double max = 0.0;

  //cout << n <<endl;
  for ( int i = 0; i < n; i++ ) {
    for ( int j = i + 1; j < n; j++) {
      if (abs(A(i,j)) > max ){
        max = abs(A(i,j));
        l = i;
        k = j;
      }
      }
    }
  return max;
}

void jacobi_rotate(arma::mat& A, arma::mat& R, int k, int l)
{
  int n = sqrt(A.size());
  double s, c;
  if ( A(k,l) != 0.0 ) {
    double t, tau;
    tau = ((A(l,l) - A(k,k))/2*A(k,l));
    if ( tau > 0 ) {
      t = 1.0/(tau + sqrt(1.0 + tau*tau));
    } else {
      t = -1.0/( -tau + sqrt(1.0 + tau*tau));
    }
    c = 1/sqrt(1+t*t);
    s = c*t;
  } else {
    c = 1.0;
    s = 0.0;
  }
  double akk, all, aik, ail, rik, ril;
  akk = A(k,k);
  all = A(l,l);

  A(k,k) = c*c*akk - 2.0*A(k,l) + s*s*all;
  A(l,l) = s*s*akk + 2.0*A(k,l) + l*l*all;

  A(l,k) = 0.0;
  A(k,l) = 0.0;

  for ( int i = 0; i < n; i++) {
    if ( i != k && i != l ) {
      aik = A(i,k);
      ail = A(i,l);
      A(i,k) = c*aik - s*ail;
      A(k,i) = A(i,k);
      A(i,l) = c*ail + s*aik;
      A(l,i) = A(i,l);
  }
  rik = R(i,k);
  ril = R(i,l);
  R(i,k) = c*aik - s*ail;
  R(i,l) = c*ail + s*aik;

  }
  return;

}
