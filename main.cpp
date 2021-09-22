#include <iostream>
#include <cmath>

#include "create_tridiagonal.hpp"
#include "matrix_operations.hpp"
#include "test_matrix.hpp"

using namespace std;

int main(int argc, char *argv[]) 
{
    test_symmetric_tridiagonal_eigenval_eigenvec();
    return 0;
}