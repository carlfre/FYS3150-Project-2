#ifndef __test_matrix__
#define test_matrix

#include <armadillo>
#include <cassert>
#include <cmath>
#include "create_tridiagonal.hpp"

//Tests that eigenvalues and vectors of matrix from
//create_symmetric_tridiagonal align with eigenvalues and 
//vectors computed with formula from project description
void test_symmetric_tridiagonal_eigenval_eigenvec();

#endif
