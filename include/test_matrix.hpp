#ifndef __test_matrix__
#define test_matrix

#include <armadillo>
#include <cassert>
#include <cmath>
#include "create_tridiagonal.hpp"
#include <iostream>

//Tests that eigenvalues and vectors of matrix from
//create_symmetric_tridiagonal align with eigenvalues and 
//vectors computed with formula from project description
void test_6_by_6_symmetric_with_eig_sym();

#endif
