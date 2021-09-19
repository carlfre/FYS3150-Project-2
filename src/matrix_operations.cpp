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
    return 0;
}
